#ifndef UMBRA_TOKEN_H
#define UMBRA_TOKEN_H

#include <stdlib.h>
#include <string.h>

enum _TokenType {
   UNKNOWN__KEYWORD = -1,
   MUTABLE__KEYWORD,
   STRING_TYPE__KEYWORD,
   NUMBER_TYPE__KEYWORD,
   MODULE_DEF__KEYWORD,
   ASSIGNMENT__OPERATOR,
   COMMENT__OPERATOR
};

struct _Token {
   int type;
   char* value;
   int line;
};

typedef struct _Token Token;

Token* token_create(int type, char* value, int line);
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