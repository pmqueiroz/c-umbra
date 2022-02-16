#ifndef UMBRA_UTIL_H
#define UMBRA_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#define Bool int

char* read_file(const char* path);

void toggle_bool(int* b);

int get_lexeme_length(const char* lexeme);

#endif
