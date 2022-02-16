#include "../include/parser.h"

Symbol* symbol_create(char* id, DataType type, char* value, InternalBool mutable) {
   Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));

   symbol->id      = id;
   symbol->type    = type;
   symbol->value   = value;
   symbol->mutable = mutable;

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

static DataType get_var_type(const TokenType type) {
   switch (type) {
      case STRING_TYPE__KEYWORD:
         return DT__STR;
         break;
      case NUMBER_TYPE__KEYWORD:
         return DT__NUM;
         break;
      case BOOL_TYPE__KEYWORD:
         return DT__BOOL;
         break;
      case HASH_TABLE_TYPE__KEYWORD:
         return DT__HASH_TABLE;
         break;
      case ARR_TYPE__KEYWORD:
         return DT__ARRAY;
         break;
      default:
         throw_sytax_error("Invalid variable type");
         break;
   }
}

void assign_var(SymbolTable* table, TokenList* list, int tokenLine) {
   TokenList    tempList       = {0};
   InternalBool is_mutable_var = 0;

   // TODO move this responsibility and only receive the temp token list
   for (int i = 0; i < list->ptr; i++) {
      Token* token = token_list_get(list, i);

      if (token->line == tokenLine) {
         token_list_add(&tempList, token);
      }
   }

   if (tempList.value[0]->type == MUTABLE__KEYWORD) {
      toggle_bool(&is_mutable_var);
   }

   // third lexeme should be the assignment operator
   if (tempList.value[2 + is_mutable_var]->type != ASSIGNMENT__OPERATOR)
      throw_sytax_error("Invalid assignment operator");

   // first lexeme should be the variable type
   DataType varType = get_var_type(tempList.value[0 + is_mutable_var]->type);

   // second lexeme should be the variable name
   char* varName = tempList.value[1 + is_mutable_var]->value;

   // fourth lexeme should be the variable value
   char* varValue = tempList.value[3 + is_mutable_var]->value;

   Symbol* sym = symbol_create(varName, varType, varValue, is_mutable_var);

   symbol_table_add(table, sym);
}
