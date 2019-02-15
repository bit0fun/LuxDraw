/* Debug Functions File */

#include "debug.h"
#define DEBUG_MODE

const char* logdir = "./";
const char* logfilename = "program.log";
const char* logfile;

void debug( const char* msg, ...) {
	va_list args;
	va_start(args, msg);
#ifdef DEBUG_MODE
	vfprintf(stdout, msg, args);
#endif
#ifndef DEBUG_MODE
	FILE *logp;
	strcat(logfile, logdir);
	strcat(logfile, logfilename);
	logp = fopen(logfile, "w");
	if(logp == NULL) {
		fprintf(stderr, "Error opening log file \n");
		return;
	}
	vfprintf(logp, msg, args);
	fclose(logp);
	va_end(args);
#endif
}

int error( int errnum, const char* msg, ...){
	va_list args;
	va_start(args, msg);

	FILE *logp;
	strcat(logfile, logdir);
	strcat(logfile, logfilename);
	logp = fopen(logfile, "w");
	if(logp == NULL) {
		fprintf(stderr, "Error opening log file \n");
		return -1;
	}
	vfprintf(logp, msg, args);
	fclose(logp);
	va_end(args);
}
