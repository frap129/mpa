 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 
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
   char exec = { find argv[1] -name '.patch' -print0 | xargs -0 patch -p1 < };
   int system(char *exec);
   exit(0);
}
