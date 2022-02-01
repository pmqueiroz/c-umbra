#include "../include/tokenize.h"

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

      // mutable instruction
      if (strcmp(lexeme, "mut") == 0) {
         token_list_add(list, token_create(TOKEN_TYPE__MUTABLE, lexeme, line));
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
