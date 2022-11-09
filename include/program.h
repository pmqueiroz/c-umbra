#ifndef UMBRA_PROGRAM_H
#define UMBRA_PROGRAM_H

#include "stack.h"

struct Program {
   char** argv; 
   long allocated;
   Stack* stack;
};

#endif
