#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <iostream>

#include <stdlib.h>
#include <vector>

#include "io/BASS_interface.h"
#include "types/Component.hpp"
#include "io/LinkedCommand.hpp"
#include "types/MakeStamps.hpp"
#include "types/ZconStamp.hpp"

using namespace std;

class Globals{
  
public:
  
  Globals();
  ~Globals();

  void initalize();
  
  int newComponent( event* the_event );
  int componentAssign( event* the_event );
  int componentEnd( event* the_event );

  int newZconstraint( event* the_event );
  int zConstraintAssign( event* the_event );
  int zConstraintEnd( event* the_event );
  
  int globalAssign( event* the_event );
  int globalEnd( event* the_event );
 
  char*  getForceField( void )      { return force_field; }
  int    getNComponents( void )     { return n_components; }
  double getTargetTemp( void )      { return target_temp; }
  double getTargetPressure( void )  { return target_pressure; }
  double getQmass( void )           { return q_mass; }
  double getTauThermostat( void )   { return tau_thermostat; }
  double getTauBarostat( void )     { return tau_barostat; }
  char*  getEnsemble( void )        { return ensemble; }
  double getDt( void )              { return dt; }
  double getRunTime( void )         { return run_time; }
 
  int    getNzConstraints( void )   { return n_zConstraints; }
  char*  getInitialConfig( void )   { return initial_config; }
  char*  getFinalConfig( void )     { return final_config; }
  int    getNMol( void )            { return n_mol; }
  double getDensity( void )         { return density; }
  double getBox( void )             { return box; }
  double getBoxX( void )            { return box_x; }
  double getBoxY( void )            { return box_y; }
  double getBoxZ( void )            { return box_z; }
  double getSampleTime( void )      { return sample_time; }
  double getStatusTime( void )      { return status_time; }
  double getResetTime( void )       { return resetTime; }
  double getThermalTime( void )     { return thermal_time; }
  double getDielectric( void )      { return dielectric; }
  double getRcut( void )            { return rcut; }
  double getRsw( void )             { return rsw; }
  int    getTempSet( void )         { return tempSet; }
  int    getUseInitTime( void )     { return useInitTime; }
  int    getUseInitXSstate( void )  { return useInitXSstate; }
  double getOrthoBoxTolerance(void) { return orthoBoxTolerance; }
  int    getPBC( void )             { return usePBC; }
  int    getUseRF( void )           { return useRF; }
  char*  getMixingRule( void)       { return mixingRule; }
  double getZconsTime(void)         { return zcons_time; }
  double getZconsTol(void)          { return zcons_tol; }
  char*  getZconsForcePolicy(void)  { return zconsForcePolicy; }
  double getZconsGap(void)          { return zcons_gap; }
  double getZconsFixtime(void)      { return zcons_fixtime; }
  int    getZconsUsingSMD(void)     { return zcons_using_smd; }
  int    getSeed(void)              { return seed; }
  char*  getMinimizer(void)         { return minimizer_name; }
  int    getMinMaxIter(void)        { return minimizer_maxiteration; }
  int    getMinWriteFrq(void)       { return minimizer_writefrq; }
  double getMinStepSize(void)       { return minimizer_stepsize; }
  double getMinFTol(void)           { return minimizer_ftol; }
  double getMinGTol(void)           { return minimizer_gtol; }
  double getMinLSTol(void)          { return minimizer_ls_tol; }
  int    getMinLSMaxIter(void)      { return minimizer_ls_maxiteration; }
  int    getUseSolidThermInt(void)  { return useSolidThermInt; }
  int    getUseLiquidThermInt(void) { return useLiquidThermInt; }
  double getThermIntLambda(void)    { return thermodynamic_integration_lambda; }
  double getThermIntK(void)         { return thermodynamic_integration_k; }
  char*  getForceFieldVariant( void ) { return forcefield_variant; }

  short int haveDt( void )            { return have_dt; }
  short int haveRunTime( void )       { return have_run_time; }
  short int haveEnsemble( void )      { return have_ensemble; }
  short int haveTargetTemp( void )    { return have_target_temp; }
  short int haveInitialConfig( void ) { return have_initial_config; }
  short int haveFinalConfig( void )   { return have_final_config; }
  short int haveNMol( void )          { return have_n_mol; }
  short int haveDensity( void )       { return have_density; }
  short int haveBox( void )           { return have_box; }
  short int haveBoxX( void )          { return have_box_x; }
  short int haveBoxY( void )          { return have_box_y; }
  short int haveBoxZ( void )          { return have_box_z; }
  short int haveSampleTime( void )    { return have_sample_time; }
  short int haveResetTime( void )     { return have_reset_time; }
  short int haveStatusTime( void )    { return have_status_time; }
  short int haveThermalTime( void )   { return have_thermal_time; }
  short int haveRcut( void )          { return have_rcut; }
  short int haveRsw( void )           { return have_rsw; }
  short int haveDielectric( void )    { return have_dielectric; }
  short int haveTempSet( void )       { return have_tempSet; }
  short int haveTargetPressure( void ){ return have_target_pressure; }
  short int haveQmass( void )         { return have_q_mass; }
  short int haveTauThermostat( void ) { return have_tau_thermostat; }
  short int haveTauBarostat( void )   { return have_tau_barostat; }
  short int haveZconstraintTime(void) { return have_zcons_time; }
  short int haveZconstraints( void )  { return have_zConstraints; }
  short int haveZconsTol(void)        { return have_zcons_tol; }
  short int haveZconsForcePolicy(void){ return have_zcons_force_policy; }
  short int haveZConsGap(void)        { return have_zcons_gap; }
  short int haveZConsFixTime(void)    { return have_zcons_fixtime; }
  short int haveZConsUsingSMD(void)   { return have_zcons_using_smd; }  
  short int haveSeed(void)            { return have_seed; }
  short int haveMinimizer(void)       { return have_minimizer; }
  short int haveMinMaxIter(void)      { return have_minimizer_maxiteration; }
  short int haveMinWriteFrq(void)     { return have_minimizer_writefrq; }
  short int haveMinStepSize(void)     { return have_minimizer_stepsize; }
  short int haveMinFTol(void)         { return have_minimizer_ftol; }
  short int haveMinGTol(void)         { return have_minimizer_gtol; }
  short int haveMinLSTol(void)        { return have_minimizer_ls_tol; }
  short int haveMinLSMaxIter(void)    { return have_minimizer_ls_maxiteration;}
  short int haveThermIntLambda(void)  { return have_thermodynamic_integration_lambda; }
  short int haveThermIntK(void)       { return have_thermodynamic_integration_k; }
  short int haveForceFieldVariant(void) { return have_forcefield_variant; }

  /* other accessors */
  Component** getComponents( void )   { return components; }
  ZconStamp** getZconStamp( void )    { return zConstraints; }
  
private:
  
  int hash_size;
  int hash_shift;
  int hash( char* text );
  void addHash( char* text, int token );
  LinkedCommand** command_table;
  
  char* checkMe( void );
  
  Component* current_component;
  Component** components; // the array of components

  ZconStamp* current_zConstraint;
  ZconStamp** zConstraints; // the array of zConstraints

  char force_field[100];
  int n_components;
  int n_zConstraints;
  double target_temp;
  double target_pressure;
  char ensemble[100];
  char mixingRule[100];
  double dt;
  double run_time;
  char initial_config[120];
  char final_config[120];
  int n_mol;
  double density;
  double box;
  double box_x, box_y, box_z;
  double sample_time;
  double status_time;
  double resetTime;
  double orthoBoxTolerance;
  double thermal_time;
  double rcut;
  double rsw;
  double dielectric;
  int tempSet;
  int useInitTime;
  int useInitXSstate;
  int usePBC;
  int useRF;
  double q_mass;
  double tau_thermostat;
  double tau_barostat;
  double zcons_time;	
  double zcons_tol;
  char zconsForcePolicy[100];
  double zcons_gap;
  double zcons_fixtime;
  int zcons_using_smd;
  
  int seed;
  char minimizer_name[100];
  int minimizer_maxiteration;
  int minimizer_writefrq;
  double minimizer_stepsize;
  double minimizer_ftol;
  double minimizer_gtol;
  double minimizer_ls_tol;
  int minimizer_ls_maxiteration;
  int useSolidThermInt;
  int useLiquidThermInt;
  double thermodynamic_integration_lambda;
  double thermodynamic_integration_k;
  char forcefield_variant[100];

  //required arguments
  short int have_force_field, have_n_components, have_target_temp;
  short int have_target_pressure, have_ensemble, have_dt, have_run_time;
  
  // optional arguments
  short int have_initial_config, have_final_config, have_n_mol;
  short int have_density, have_box, have_box_x, have_box_y, have_box_z;
  short int have_sample_time, have_status_time, have_rcut, have_dielectric;
  short int have_tempSet, have_thermal_time, have_rsw, have_q_mass;
  short int have_tau_thermostat, have_tau_barostat;
  short int have_zcons_time, have_zConstraints, have_n_zConstraints;
  short int have_zcons_tol, have_seed;
  short int have_zcons_force_policy, have_reset_time;
  short int have_zcons_gap, have_zcons_fixtime;
  short int have_zcons_using_smd;
  short int have_minimizer, have_minimizer_maxiteration;
  short int have_minimizer_writefrq, have_minimizer_stepsize;
  short int have_minimizer_ftol, have_minimizer_gtol;
  short int have_minimizer_ls_tol, have_minimizer_ls_maxiteration;
  short int have_thermodynamic_integration_lambda;
  short int have_thermodynamic_integration_k;
  short int have_forcefield_variant;
};

#endif
