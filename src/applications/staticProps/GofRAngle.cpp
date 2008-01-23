/*
 * Copyright (c) 2005 The University of Notre Dame. All Rights Reserved.
 *
 * The University of Notre Dame grants you ("Licensee") a
 * non-exclusive, royalty free, license to use, modify and
 * redistribute this software in source and binary code form, provided
 * that the following conditions are met:
 *
 * 1. Acknowledgement of the program authors must be made in any
 *    publication of scientific results based in part on use of the
 *    program.  An acceptable form of acknowledgement is citation of
 *    the article in which the program was described (Matthew
 *    A. Meineke, Charles F. Vardeman II, Teng Lin, Christopher
 *    J. Fennell and J. Daniel Gezelter, "OOPSE: An Object-Oriented
 *    Parallel Simulation Engine for Molecular Dynamics,"
 *    J. Comput. Chem. 26, pp. 252-271 (2005))
 *
 * 2. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 3. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 * This software is provided "AS IS," without a warranty of any
 * kind. All express or implied conditions, representations and
 * warranties, including any implied warranty of merchantability,
 * fitness for a particular purpose or non-infringement, are hereby
 * excluded.  The University of Notre Dame and its licensors shall not
 * be liable for any damages suffered by licensee as a result of
 * using, modifying or distributing the software or its
 * derivatives. In no event will the University of Notre Dame or its
 * licensors be liable for any lost revenue, profit or data, or for
 * direct, indirect, special, consequential, incidental or punitive
 * damages, however caused and regardless of the theory of liability,
 * arising out of the use of or inability to use software, even if the
 * University of Notre Dame has been advised of the possibility of
 * such damages.
 */

#include <algorithm>
#include <fstream>
#include "applications/staticProps/GofRAngle.hpp"
#include "utils/simError.h"

namespace oopse {

  GofRAngle::GofRAngle(SimInfo* info, const std::string& filename, const std::string& sele1, 
		       const std::string& sele2, RealType len, int nrbins, int nangleBins)
    : RadialDistrFunc(info, filename, sele1, sele2), len_(len), nRBins_(nrbins), nAngleBins_(nangleBins){

      deltaR_ = len_ /(double) nRBins_;
      deltaCosAngle_ = 2.0 / (double)nAngleBins_;    
      histogram_.resize(nRBins_);
      avgGofr_.resize(nRBins_);
      for (int i = 0 ; i < nRBins_; ++i) {
        histogram_[i].resize(nAngleBins_);
        avgGofr_[i].resize(nAngleBins_);
      }
    }


  void GofRAngle::preProcess() {
    for (int i = 0; i < avgGofr_.size(); ++i) {
      std::fill(avgGofr_[i].begin(), avgGofr_[i].end(), 0);
    }
  }

  void GofRAngle::initalizeHistogram() {
    npairs_ = 0;
    for (int i = 0; i < histogram_.size(); ++i){
      std::fill(histogram_[i].begin(), histogram_[i].end(), 0);
    }
  }

  void GofRAngle::processHistogram() {
    int nPairs = getNPairs();
    RealType volume = info_->getSnapshotManager()->getCurrentSnapshot()->getVolume();
    RealType pairDensity = nPairs /volume;
    RealType pairConstant = ( 4.0 * NumericConstant::PI * pairDensity ) / 3.0;

    for(int i = 0 ; i < histogram_.size(); ++i){

      RealType rLower = i * deltaR_;
      RealType rUpper = rLower + deltaR_;
      RealType volSlice = ( rUpper * rUpper * rUpper ) - ( rLower * rLower * rLower );
      RealType nIdeal = volSlice * pairConstant;

      for (int j = 0; j < histogram_[i].size(); ++j){
	avgGofr_[i][j] += histogram_[i][j] / nIdeal;    
      }
    }

  }

  void GofRAngle::collectHistogram(StuntDouble* sd1, StuntDouble* sd2) {

    if (sd1 == sd2) {
      return;
    }
    Vector3d pos1 = sd1->getPos();
    Vector3d pos2 = sd2->getPos();
    Vector3d r12 = pos2 - pos1;
    if (usePeriodicBoundaryConditions_)
      currentSnapshot_->wrapVector(r12);

    RealType distance = r12.length();
    int whichRBin = distance / deltaR_;

    if (distance <= len_) {

      RealType cosAngle = evaluateAngle(sd1, sd2);
      RealType halfBin = (nAngleBins_ - 1) * 0.5;
      int whichThetaBin = halfBin * (cosAngle + 1.0);
      ++histogram_[whichRBin][whichThetaBin];
        
      ++npairs_;
    }
  }

  void GofRAngle::writeRdf() {
    std::ofstream rdfStream(outputFilename_.c_str());
    if (rdfStream.is_open()) {
      rdfStream << "#radial distribution function\n";
      rdfStream << "#selection1: (" << selectionScript1_ << ")\t";
      rdfStream << "selection2: (" << selectionScript2_ << ")\n";
      rdfStream << "#nRBins = " << nRBins_ << "\t maxLen = " << len_ << "deltaR = " << deltaR_ <<"\n";
      rdfStream << "#nAngleBins =" << nAngleBins_ << "deltaCosAngle = " << deltaCosAngle_ << "\n";
      for (int i = 0; i < avgGofr_.size(); ++i) {
	RealType r = deltaR_ * (i + 0.5);

	for(int j = 0; j < avgGofr_[i].size(); ++j) {
	  RealType cosAngle = -1.0 + (j + 0.5)*deltaCosAngle_;
	  rdfStream << avgGofr_[i][j]/nProcessed_ << "\t";
	}

	rdfStream << "\n";
      }
        
    } else {
      sprintf(painCave.errMsg, "GofRAngle: unable to open %s\n", outputFilename_.c_str());
      painCave.isFatal = 1;
      simError();  
    }

    rdfStream.close();
  }

  RealType GofRTheta::evaluateAngle(StuntDouble* sd1, StuntDouble* sd2) {
    Vector3d pos1 = sd1->getPos();
    Vector3d pos2 = sd2->getPos();
    Vector3d r12 = pos2 - pos1;
  
    if (usePeriodicBoundaryConditions_)
      currentSnapshot_->wrapVector(r12);

    r12.normalize();
    Vector3d dipole = sd1->getElectroFrame().getColumn(2);
    dipole.normalize();    
    return dot(r12, dipole);
  }

  RealType GofROmega::evaluateAngle(StuntDouble* sd1, StuntDouble* sd2) {
    Vector3d v1 = sd1->getElectroFrame().getColumn(2);
    Vector3d v2 = sd2->getElectroFrame().getColumn(2);    
    v1.normalize();
    v2.normalize();
    return dot(v1, v2);
  }


}


