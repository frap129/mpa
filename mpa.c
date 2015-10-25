 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>

 #define MAX_CMD_LEN 150

 int main(int argc, char *argv[])
{
 /* Argument Handling */
   if( argc > 3 ) {
      printf("Too many arguments.\n ");
      exit(1);
   } else if( argc < 2) {
      printf("No directory defined.\n Usage: mpa /patch/directory\n");
      exit(1);
   } else {
      printf("Using directory %s\n", argv[1]);
   }

   /* Patch Applier */
   const char * find = "find ";
   const char * args = " -name '.patch' -print0 | xargs -0 patch -p1";
   char mpa[MAX_CMD_LEN];
   strcat(mpa, find);
   strcat(mpa, argv[1]);
   strcat(mpa, args);
   system(mpa);
   exit(0);
}
