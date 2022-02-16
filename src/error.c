#include "../include/error.h"

void throw_error(const char* msg) {
   printf("%s\n", msg);

   exit(EXIT_FAILURE);
};

void throw_sytax_error(const char* msg) { throw_error(strcat("Syntax Error: ", msg)); };
