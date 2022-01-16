#ifndef UMBRA_INTERPRETER_H
#define UMBRA_INTERPRETER_H

#include <string.h>
#include "token.h"

void interpreter_run(char* code, TokenList* list);

#endif