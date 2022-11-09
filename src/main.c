#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/symbol.h"
#include "../include/token.h"
#include "../include/tokenizer.h"
#include "../include/util.h"

#define MAX_TYPE_SIZE 28

static char* generate_white_spaces(int n, int max) {
   int   remaining_size  = max - n;
   char* allocated_value = (char*)malloc(remaining_size * sizeof(char));
   char  white_spaces[remaining_size];

   memset(white_spaces, ' ', remaining_size);

   white_spaces[remaining_size] = '\0';

   strcpy(allocated_value, white_spaces);

   return allocated_value;
}

static void print_tokens(TokenList* list) {
   char* template     = "<type: %s, %s value: '%s', %s ln: %d, col: %d>\n";
   int max_value_size = 0;

   for (int i = 0; i < list->ptr; i++) {
      Token* token  = token_list_get(list, i);
      int    length = get_lexeme_length(token->value);

      if (length > max_value_size) {
         max_value_size = length;
      }
   }

   for (int i = 0; i < list->ptr; i++) {
      Token* token       = token_list_get(list, i);
      char*  token_name  = get_token_type_name(token->type);
      char*  keywords_ws = generate_white_spaces(get_lexeme_length(token_name), MAX_TYPE_SIZE);
      char*  values_ws   = generate_white_spaces(get_lexeme_length(token->value), max_value_size);

      printf(template, token_name, keywords_ws, token->value, values_ws, token->line,
             token->column);

      free(keywords_ws);
      free(values_ws);
   }
}

void print_table(SymbolTable* table) {
   char* template = "| %d, %s, %s, %d |\n";

   for (int i = 0; i < table->ptr; i++) {
      Symbol*  symbol = symbol_table_get(table, i);
      DataType type   = symbol->type;
      char*    id     = symbol->id;
      char*    value  = symbol->value;
      int mutable     = symbol->mutable;

      printf(template, type, id, value, mutable);
   }
}

int main(int argc, char** argv) {
   if (strcmp(argv[1], "--help") == 0) {
      printf("Usage: %s compile <file>.umb\n", argv[0]);
      return 0;
   }

   // character stream
   char* code = read_file(argv[1]);

   // token stream
   TokenList tokens = {0};
   generate_tokens(code, &tokens);

   print_tokens(&tokens);

   // symbol table
   SymbolTable symbols = {0};
   // generate_symbol_table(&symbols, &tokens);

   assign_var(&symbols, &tokens, 5);
   assign_var(&symbols, &tokens, 6);

   print_table(&symbols);

   free(code);

   return 0;
}
