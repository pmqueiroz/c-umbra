#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"

int main(int argc, char** argv) {
   if (strcmp(argv[1], "--help") == 0) {
      printf("Usage: %s compile <file>.umb\n", argv[0]);
      return 0;
   }

   char* source = read_file(argv[1]);
   printf("%s\n", source);
   free(source);

   return 0;
}