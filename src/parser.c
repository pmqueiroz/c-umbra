#include "../include/parser.h"

Symbol* symbol_create(char* id, DataType type, char* value, int mutable) {
   Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));

   symbol->id    = id;
   symbol->type  = type;
   symbol->value = value;
   // TODO fix this null
   symbol->readonly = NULL;

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

DataType get_symbol_type(char* lexeme) {}

static DataType get_var_type(const char* buf) {
   if (strcmp(buf, "str") == 0)
      return DT__STR;
   if (strcmp(buf, "num") == 0)
      return DT__NUM;
   if (strcmp(buf, "bool") == 0)
      return DT__BOOL;
   if (strcmp(buf, "hash") == 0)
      return DT__HASH_TABLE;
   if (strcmp(buf, "arr") == 0)
      return DT__ARRAY;

   throw_sytax_error("Invalid variable type");
}

void assign_var(SymbolTable* table, TokenList* list, int tokenLine) {
   TokenList tempList       = {0};
   int       is_mutable_var = 0;

   // TODO move this responsibility and only receive the temp token list
   for (int i = 0; i < list->ptr; i++) {
      Token* token = token_list_get(list, i);

      if (token->line == tokenLine) {
         token_list_add(&tempList, token);
      }
   }

   if (strcmp(tempList.value[0]->value, "mut") == 0) {
      toggle_bool(&is_mutable_var);
   }

   // third lexeme should be the assignment operator
   if (strcmp(tempList.value[2 + is_mutable_var]->value, "<-") != 0)
      throw_sytax_error("Invalid assignment operator");

   // first lexeme should be the variable type
   DataType varType = get_var_type(tempList.value[0 + is_mutable_var]->value);

   // second lexeme should be the variable name
   char* varName = tempList.value[1 + is_mutable_var]->value;

   // fourth lexeme should be the variable value
   char* varValue = tempList.value[3 + is_mutable_var]->value;

   Symbol* sym = symbol_create(varName, varType, varValue, 2);

   symbol_table_add(table, sym);
}
