/** @file SequentialPropsCmd.hpp
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef SEQUENTIALPROPSCMD_H
#define SEQUENTIALPROPSCMD_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE "SequentialProps"
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_PACKAGE_NAME "SequentialProps"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION ""
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char * input_arg;	/**< @brief input dump file.  */
  char * input_orig;	/**< @brief input dump file original value given at command line.  */
  const char *input_help; /**< @brief input dump file help description.  */
  char * output_arg;	/**< @brief output file name.  */
  char * output_orig;	/**< @brief output file name original value given at command line.  */
  const char *output_help; /**< @brief output file name help description.  */
  char * sele1_arg;	/**< @brief select first stuntdouble set.  */
  char * sele1_orig;	/**< @brief select first stuntdouble set original value given at command line.  */
  const char *sele1_help; /**< @brief select first stuntdouble set help description.  */
  char * sele2_arg;	/**< @brief select second stuntdouble set (if sele2 is not set, use script from sele1).  */
  char * sele2_orig;	/**< @brief select second stuntdouble set (if sele2 is not set, use script from sele1) original value given at command line.  */
  const char *sele2_help; /**< @brief select second stuntdouble set (if sele2 is not set, use script from sele1) help description.  */
  int nbins_arg;	/**< @brief number of bins (general purpose) (default='100').  */
  char * nbins_orig;	/**< @brief number of bins (general purpose) original value given at command line.  */
  const char *nbins_help; /**< @brief number of bins (general purpose) help description.  */
  int nbins_z_arg;	/**< @brief number of bins in z axis (default='100').  */
  char * nbins_z_orig;	/**< @brief number of bins in z axis original value given at command line.  */
  const char *nbins_z_help; /**< @brief number of bins in z axis help description.  */
  double centroidX_arg;	/**< @brief Location of droplet centroid in x.  */
  char * centroidX_orig;	/**< @brief Location of droplet centroid in x original value given at command line.  */
  const char *centroidX_help; /**< @brief Location of droplet centroid in x help description.  */
  double centroidY_arg;	/**< @brief Location of droplet centroid in y.  */
  char * centroidY_orig;	/**< @brief Location of droplet centroid in y original value given at command line.  */
  const char *centroidY_help; /**< @brief Location of droplet centroid in y help description.  */
  double referenceZ_arg;	/**< @brief Reference z-height of solid surface.  */
  char * referenceZ_orig;	/**< @brief Reference z-height of solid surface original value given at command line.  */
  const char *referenceZ_help; /**< @brief Reference z-height of solid surface help description.  */
  double dropletR_arg;	/**< @brief Droplet radius in angstroms.  */
  char * dropletR_orig;	/**< @brief Droplet radius in angstroms original value given at command line.  */
  const char *dropletR_help; /**< @brief Droplet radius in angstroms help description.  */
  double threshDens_arg;	/**< @brief Threshold Density in g/cm^3.  */
  char * threshDens_orig;	/**< @brief Threshold Density in g/cm^3 original value given at command line.  */
  const char *threshDens_help; /**< @brief Threshold Density in g/cm^3 help description.  */
  double bufferLength_arg;	/**< @brief Buffer length in angstroms.  */
  char * bufferLength_orig;	/**< @brief Buffer length in angstroms original value given at command line.  */
  const char *bufferLength_help; /**< @brief Buffer length in angstroms help description.  */
  double rcut_arg;	/**< @brief cutoff radius (rcut).  */
  char * rcut_orig;	/**< @brief cutoff radius (rcut) original value given at command line.  */
  const char *rcut_help; /**< @brief cutoff radius (rcut) help description.  */
  const char *com_help; /**< @brief selection center of mass help description.  */
  const char *comvel_help; /**< @brief selection center of mass velocity help description.  */
  const char *ca1_help; /**< @brief contact angle of selection (using center of mass) help description.  */
  const char *ca2_help; /**< @brief contact angle of selection (using density profile) help description.  */
  const char *gcn_help; /**< @brief Generalized Coordinate Number help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int input_given ;	/**< @brief Whether input was given.  */
  unsigned int output_given ;	/**< @brief Whether output was given.  */
  unsigned int sele1_given ;	/**< @brief Whether sele1 was given.  */
  unsigned int sele2_given ;	/**< @brief Whether sele2 was given.  */
  unsigned int nbins_given ;	/**< @brief Whether nbins was given.  */
  unsigned int nbins_z_given ;	/**< @brief Whether nbins_z was given.  */
  unsigned int centroidX_given ;	/**< @brief Whether centroidX was given.  */
  unsigned int centroidY_given ;	/**< @brief Whether centroidY was given.  */
  unsigned int referenceZ_given ;	/**< @brief Whether referenceZ was given.  */
  unsigned int dropletR_given ;	/**< @brief Whether dropletR was given.  */
  unsigned int threshDens_given ;	/**< @brief Whether threshDens was given.  */
  unsigned int bufferLength_given ;	/**< @brief Whether bufferLength was given.  */
  unsigned int rcut_given ;	/**< @brief Whether rcut was given.  */
  unsigned int com_given ;	/**< @brief Whether com was given.  */
  unsigned int comvel_given ;	/**< @brief Whether comvel was given.  */
  unsigned int ca1_given ;	/**< @brief Whether ca1 was given.  */
  unsigned int ca2_given ;	/**< @brief Whether ca2 was given.  */
  unsigned int gcn_given ;	/**< @brief Whether gcn was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
  int sequentialProps_group_counter; /**< @brief Counter for group sequentialProps */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief the description string of the program */
extern const char *gengetopt_args_info_description;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SEQUENTIALPROPSCMD_H */
