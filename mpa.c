 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>

 #define MAX_CMD_LEN 1000

 int main(int argc, char *argv[])
{
 /* Argument Handling */
   if( argc > 3 ) {
      printf("Too many arguments.\n Usage: mpa /patch/directory\n");
      exit(1);
   } else if( argc < 2) {
      printf("No directory defined.\n Usage: mpa /patch/directory\n");
      exit(1);
   } else {
      printf("Using directory %s\n", argv[1]);
   }

   /* Patch Applier */
   const char * find = "find ";
   const char * dir = argv[1];
   const char * args = " -name '*.patch' -print0 | xargs -0 patch -p1";
   char mpa_patcher[MAX_CMD_LEN];
   strcpy(mpa_patcher, find);
   strcat(mpa_patcher, dir);
   strcat(mpa_patcher, args);
   system(mpa_patcher);
}
