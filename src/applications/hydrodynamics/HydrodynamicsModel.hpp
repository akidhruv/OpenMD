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
#ifndef APPLICATION_HYDRODYNAMICS_HYDRODYNAMICSMODEL_HPP
#define APPLICATION_HYDRODYNAMICS_HYDRODYNAMICSMODEL_HPP
#include <vector>

#include "math/Vector3.hpp"
#include "math/SquareMatrix3.hpp"
#include "math/DynamicRectMatrix.hpp"
#include "primitives/Molecule.hpp"
#include "applications/hydrodynamics/StuntDoubleShape.hpp"
#include "utils/any.hpp"
namespace oopse {
struct HydrodynamicProps {
    Vector3d diffCenter;
    Mat3x3d Ddtt;
    Mat3x3d Ddtr;
    Mat3x3d Ddrr;
    Mat3x3d Xidtt;
    Mat3x3d Xidrt;
    Mat3x3d Xidtr;
    Mat3x3d Xidrr;
};

struct BeadParam {
    std::string atomName;
    Vector3d pos;
    double radius;
};

typedef std::map<std::string, boost::any> DynamicProperty;

class HydrodynamicsModel {
    public:
        HydrodynamicsModel(StuntDouble* sd, const DynamicProperty& extraParams);
        bool calcHydrodyanmicsProps();

        Vector3d getDiffCenter();
        Mat3x3d getTransDiff();
        Mat3x3d getRotDiff();
        Mat3x3d getTransRotDiff();
        void writeBeads(std::ostream& os);
        void writeDiffCenterAndDiffTensor(std::ostream& os);
    protected:
        StuntDouble* sd_;
    private:
        virtual bool createBeads(std::vector<BeadParam>& beads) = 0;

        void calcResistanceTensor();
        void calcDiffusionTensor();
        HydrodynamicProps props_;
        std::vector<BeadParam> beads_;
        double viscosity_;
        double temperature_;
        
};


}

#endif