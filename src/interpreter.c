#include "../include/interpreter.h"

void interpreter_run(char* code, TokenList* list) {
   char lex[256];
   int lexi = 0;
   int i = 0;
   int line = 1;

   while (1) {
      memset(lex, 0, 256);

      while (code[i] != ' ' && code[i] != '\n' && code[i] != '\0') {
         lex[lexi++] = code[i++];
      }

      lex[lexi] = '\0';

      // var instruction
      if (strcmp(lex, "var") == 0) {
         token_list_add(list, token_create(TOKEN_TYPE_VARIABLE, 1 ,line));
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
