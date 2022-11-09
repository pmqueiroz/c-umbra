#ifndef UMBRA_STACK_H
#define UMBRA_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

struct Stack {
    int maxsize;
    int top;
    int *items;
};

#endif
