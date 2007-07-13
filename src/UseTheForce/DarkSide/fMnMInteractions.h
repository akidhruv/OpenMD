#ifdef __C
#ifndef __FMNMINTERACTIONS
#define __FMNMINTERACTIONS

#define MNM_NUM_MNM_TYPES 4
#define MNM_LENNARDJONES  1
#define MNM_REPULSIVEMORSE 2
#define MNM_SHIFTEDMORSE 3
#define MNM_MAW 4

typedef  struct{
  int MNMInteractionType;
  int metal_atid;
  int nonmetal_atid;
  RealType R0;
  RealType D0;
  RealType beta0;  
  RealType betaH;  
  RealType alpha;  
  RealType gamma;  
  RealType sigma;
  RealType epsilon;
} MNMtype;


#endif
#endif /*__C*/

#ifdef  __FORTRAN90

  INTEGER, PARAMETER:: MNM_NUM_MNM_TYPES = 4
  INTEGER, PARAMETER:: MNM_LENNARDJONES  = 1
  INTEGER, PARAMETER:: MNM_REPULSIVEMORSE = 2
  INTEGER, PARAMETER:: MNM_SHIFTEDMORSE = 3
  INTEGER, PARAMETER:: MNM_MAW = 4

  type :: MNMtype
    SEQUENCE
    integer :: MNMInteractionType
    integer :: metal_atid;
    integer :: nonmetal_atid;
    real(kind=dp) :: R0
    real(kind=dp) :: D0
    real(kind=dp) :: beta0
    real(kind=dp) :: betaH
    real(kind=dp) :: alpha
    real(kind=dp) :: gamma
    real(kind=dp) :: sigma
    real(kind=dp) :: epsilon
  end type MNMtype

#endif
