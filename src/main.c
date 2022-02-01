#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"
#include "../include/tokenize.h"
#include "../include/token.h"

int main(int argc, char** argv) {
   if (strcmp(argv[1], "--help") == 0) {
      printf("Usage: %s compile <file>.umb\n", argv[0]);
      return 0;
   }

   char* code = read_file(argv[1]);

   TokenList tokens = {0};
   generate_tokens(code, &tokens);

   for (int i = 0; i < tokens.ptr; i++) {
      Token* token = token_list_get(&tokens, i);
      printf("<type: %d, value: %s, line: %d>\n", token->type, token->value, token->line);
   }
   
   free(code);

   return 0;
}