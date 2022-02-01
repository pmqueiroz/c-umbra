#include "../include/tokenizer.h"
#include <stdio.h>

void generate_tokens(char* code, TokenList* list) {
   char lexeme[256];
   int lexi = 0;
   int i = 0;
   int line = 1;

   while (1) {
      memset(lexeme, 0, sizeof(lexeme));

      while (code[i] != ' ' && code[i] != '\n' && code[i] != '\0') {
         lexeme[lexi++] = code[i++];
      }

      lexeme[lexi] = '\0';

      if (strcmp(lexeme, "mut") == 0) {
         token_list_add(list, token_create(MUTABLE__KEYWORD, lexeme, line));
      } else if (strcmp(lexeme, "str") == 0) {
         token_list_add(list, token_create(STRING_TYPE__KEYWORD, lexeme, line));
      } else if (strcmp(lexeme, "num") == 0) {
         token_list_add(list, token_create(NUMBER_TYPE__KEYWORD, lexeme, line));
      } else if (strcmp(lexeme, "package") == 0) {
         token_list_add(list, token_create(MODULE_DEF__KEYWORD, lexeme, line));
      } else if (strcmp(lexeme, "<-") == 0) {
         token_list_add(list, token_create(ASSIGNMENT__OPERATOR, lexeme, line));
      } else if (strcmp(lexeme, "#") == 0) {
         token_list_add(list, token_create(COMMENT__OPERATOR, lexeme, line));
      } else {
         token_list_add(list, token_create(UNKNOWN__KEYWORD, lexeme, line));
      }
      
      // new line
      if (code[i] == '\n') {
         line++;
      }
      
      // eof
      if (code[i] == '\0') {
         break;
      }

      lexi = 0;
      i++;
   }
}
