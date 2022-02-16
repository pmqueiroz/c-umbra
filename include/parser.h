#ifndef UMBRA_PARSER_H
#define UMBRA_PARSER_H

#include "token.h"

enum _DataType { DT__NUM, DT__STR, DT__BOOL, DT__HASH_TABLE, DT__FUNCTION, DT__ARRAY };

typedef enum _DataType DataType;

struct _Symbol {
   DataType type;
   char*    id;
   int      memloc;
};

typedef struct _Symbol Symbol;

struct _SymbolTable {
   Symbol** value;
   int      ptr;
   int      size;
};

typedef struct _SymbolTable SymbolTable;

Symbol* symbol_create(Token* token);

void symbol_destroy(Symbol* symbol);

void    symbol_table_add(SymbolTable* table, Symbol symbol);
Symbol* symbol_table_get(SymbolTable* table, int index);

#endif
