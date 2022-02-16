#ifndef UMBRA_UTIL_H
#define UMBRA_UTIL_H

#include <stdio.h>
#include <stdlib.h>

enum _InternalBool { I_FALSE, I_TRUE };

typedef enum _InternalBool InternalBool;

char* read_file(const char* path);

void toggle_bool(InternalBool* b);

int get_lexeme_length(const char* lexeme);

#endif
