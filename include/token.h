#ifndef UMBRA_TOKEN_H
#define UMBRA_TOKEN_H

#include <stdlib.h>

enum _TokenType {
   TOKEN_TYPE_MUTABLE
};

struct _Token {
   int type;
   int value;
   int line;
};

typedef struct _Token Token;

Token* token_create(int type, int value, int line);
void token_destroy(Token* token);

struct _TokenList {
   Token** value;
   int ptr;
   int size;
};

typedef struct _TokenList TokenList;

void token_list_add(TokenList* list, Token* token);
Token* token_list_get(TokenList* list, int index);

#endif