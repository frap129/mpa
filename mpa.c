#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CMD_LEN 1000

int main(int argc, char *argv[]) {
 /*
  * Argument Handling
  */

    /* make sure arguments are formated correctly */
  if( argc > 3 ) {
     printf("Too many arguments.\n Usage: mpa /patch/directory [OPTIONS: -s (--solo: Do not search for patches recursively)]\n");
     exit(1);
  } else if( argc < 2 ) {
     printf("No directory defined.\n Usage: mpa /patch/directory [OPTIONS: -s (--solo: Do not search for patches recursively)]\n");
     exit(1);
  } else {
     printf("Using directory %s\n", argv[1]);
  }

    /* Create some char* values for argument handling needs */
  const char* sflag = argv[2];
  const char* nada;  /* Empty value, hence 'nada' */

 /*
  * Patch Applier
  */

    /* Create necesary strings */
  const char* find = "find ";
  const char* dir = argv[1];
  const char* args = " -name '*.patch' -print0 | xargs -0 patch -p1";
  const char* maxdepth = " -maxdepth 1";
  char* mpa_patcher[MAX_CMD_LEN];

    /* Concatenate strings to form main command */
  strcpy(mpa_patcher, find);
  strcat(mpa_patcher, dir);
  if( sflag !=  nada ){
     strcat(mpa_patcher, maxdepth);  /* Only use -maxdepth 1 for non-recursive */
  }
  strcat(mpa_patcher, args);

    /* Execute command with system() */
  int ret = system(mpa_patcher);
  if( ret == nada ) {
     return 1;
     printf("Error code 1: No patch result");
     exit(1);
  } else {
     return 0;
     exit(0);
  }
}
