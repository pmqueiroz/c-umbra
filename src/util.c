#include "../include/util.h"

char* read_file(const char* path) {
   FILE* file = fopen(path, "r");
   if (!file) {
      printf("Could not open file\n");
      return NULL;
   }

   fseek(file, 0, SEEK_END);
   long size = ftell(file);
   fseek(file, 0, SEEK_SET);

   char* buffer = (char*)malloc(sizeof(char) * (size + 1));

   if (!buffer) {
      printf("Could not allocate memory\n");
      return NULL;
   }

   fread(buffer, 1, size, file);
   buffer[size] = '\0';
   fclose(file);

   return buffer;
}