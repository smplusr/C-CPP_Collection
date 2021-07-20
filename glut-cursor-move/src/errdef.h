/* This header file contains the definitions of all the error codes used through the program.
 * This header might be included in multiple other headers files or source files. */

/* Guard clause of the error definition */
#ifndef ERRDEF_H
#define ERRDEF_H

/* Definition of the type ERROR, which must be an integer
 * and declaration of all the error codes used throuhout the program. */
typedef int ERROR;


/* Code returned when no error occured. */
static ERROR const NO_ERROR = { 0 };

/* Error returned when GLUT failed to start and return 
 * a GLUT_INIT_STATE value equal to 0. */
static ERROR const FAILED_TO_INITIALISE_GLUT = { 1 };

/* Error return when the Display class Init function 
 * returns not a null value.*/
static ERROR const FAILED_TO_INITIALISE_DISPLAY = { 2 };

#endif
