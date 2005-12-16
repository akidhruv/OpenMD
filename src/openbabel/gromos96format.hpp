/**********************************************************************
Copyright (C) 1998-2001 by OpenEye Scientific Software, Inc.
Some portions Copyright (C) 2001-2005 by Geoffrey R. Hutchison
Some portions Copyright (C) 2004 by Chris Morley
 
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation version 2 of the License.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
***********************************************************************/

/* contributed by Walter Scott (wscott@igc.phys.chem.ethz.ch)
 
   (Actually the routine was copied from write_xyz and and write_pdb and
   then modified...)
 
   This is a small routine to write a GROMOS96 formatted 
   "position coordinate block" (POSITION) or a
   "reduced position coordinate block" (POSITIONRED)
   The former has name information (atom and residue names) while
   the latter only has coordinates.
   This version does not support the writing of binary
   GROMOS files.
 
   NOTE 1: the actual formats used in writing out the coordinates
   do not matter, as GROMOS96 uses free formatted reads.
   Each line may not be longer than 80 characters.
 
   (Note, however, in the POSITION block, the first 24 (twenty four)
   character on each line are ignored when the line is read in by GROMOS)
   Comments lines, beginning with hash (#) may occur within a block and are
   used as delimiters for easier reading.
 
   NOTE 2: Many programs specify the units of the coordinates (e.g. Angstrom).
   GROMOS96 does NOT, as all physical constants, from K_B to EPS are 
   NOT hardwired into the code, but specified by the user.
   This allows some (mostly Americans) to use GROMOS96 in KCal and
   Angstrom and the rest of us to use kJoule and nm.
   It also makes it easy to use reduced units.
 
   We get around this by supplying a routine, wr_sco_gr96, which
   will scale the coordinates by a factor before writing.
   This routine is then called with the factor set to 1.0 in 
   write_gr96A, or to 0.1 in write_gr96N depending on the users choice.
   Thus, we always assume that we have read coordinates in Angstrom.
	 *** But now handled by a command line option in new framework.
*/

#ifndef OB_GROMOS96FORMAT_HPP
#define OB_GROMOS96FORMAT_HPP

#include "mol.hpp"
#include "obconversion.hpp"

using namespace std;
namespace OpenBabel
{

class GROMOS96Format : public OBFormat
{
public:
    //Register this format type ID
    GROMOS96Format()
    {
        OBConversion::RegisterFormat("gr96",this);
    }

  virtual const char* Description() //required
  {
    return
      "GROMOS96 format\n \
       Write Options e.g. -xn\n\
        n output nm (not Angstroms)\n";
  };

    virtual const char* SpecificationURL()
    {
        return "";
    }; //optional

    //Flags() can return be any the following combined by | or be omitted if none apply
    // NOTREADABLE  READONEONLY  NOTWRITABLE  WRITEONEONLY
    virtual unsigned int Flags()
    {
        return NOTREADABLE | WRITEONEONLY;
    };

    ////////////////////////////////////////////////////
    /// The "API" interface functions
    virtual bool WriteMolecule(OBBase* pOb, OBConversion* pConv);

    ////////////////////////////////////////////////////
    /// The "Convert" interface functions
    virtual bool WriteChemObject(OBConversion* pConv)
    {
        //Retrieve the target OBMol
        OBBase* pOb = pConv->GetChemObject();
        OBMol* pmol = dynamic_cast<OBMol*> (pOb);
        bool ret=false;
        if(pmol)
            ret=WriteMolecule(pmol,pConv);

	std::string auditMsg = "OpenBabel::Write molecule ";
	std::string description(Description());
        auditMsg += description.substr( 0, description.find('\n') );
        obErrorLog.ThrowError(__func__,
                              auditMsg,
                              obAuditMsg);

        delete pOb;
        return ret;
    };
};
}
#endif
