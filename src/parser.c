#include "../include/parser.h"

Symbol* symbol_create(Token* token) {
   Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));

   symbol->id   = token->value;
   symbol->type = token->type;

   return symbol;
}

void symbol_destroy(Symbol* symbol) { free(symbol); }

void symbol_table_add(SymbolTable* table, Symbol* symbol) {
   if (table->ptr >= table->size) {
      table->size += 1;
      table->value = (Symbol**)realloc(table->value, sizeof(Symbol**) * table->size);
   }

   table->value[table->ptr++] = symbol;
}

Symbol* symbol_table_get(SymbolTable* table, int index) { return table->value[index]; }
