/* Debug Function Header */
#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>


/* Debug function */
void debug( const char* msg, ...);

/* Error Function */
int error( int errmum, const char* msg, ...);





#endif /* DEBUG_H */
