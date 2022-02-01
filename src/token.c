#include "../include/token.h"

Token* token_create(int type, char* value, int line) {
   Token* token = (Token*) malloc(sizeof(Token));

   token->type = type;
   token->value = value;
   token->line = line;

   return token;
}

void token_destroy(Token* token) {
   free(token);
}

void token_list_add(TokenList* list, Token* token) {
   if (list->ptr >= list->size) {
      list->size += 1;
      list->value = (Token**) realloc(list->value, sizeof(Token**) * list->size);
   }

   list->value[list->ptr++] = token;
}

Token* token_list_get(TokenList* list, int index) {
   return list->value[index];
}
