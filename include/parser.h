#ifndef UMBRA_PARSER_H
#define UMBRA_PARSER_H

#include "error.h"
#include "token.h"
#include "util.h"

enum _DataType { DT__NUM, DT__STR, DT__BOOL, DT__HASH_TABLE, DT__ARRAY };

typedef enum _DataType DataType;

struct _Symbol {
   DataType type;
   Bool     readonly;
   char*    id;
   char*    value;
};

typedef struct _Symbol Symbol;

struct _SymbolTable {
   Symbol** value;
   int      ptr;
   int      size;
};

typedef struct _SymbolTable SymbolTable;

Symbol* symbol_create(char* id, DataType type, char* value, int mutable);

void symbol_destroy(Symbol* symbol);

void    symbol_table_add(SymbolTable* table, Symbol* symbol);
Symbol* symbol_table_get(SymbolTable* table, int index);

void generate_symbol_table(SymbolTable* table, TokenList* list);

void assign_var(SymbolTable* table, TokenList* list, int tokenLine);

#endif
