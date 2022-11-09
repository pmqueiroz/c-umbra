#ifndef UMBRA_AST_H
#define UMBRA_AST_H

#include <stddef.h>
#include "shared.h"

struct _Identifier {
    size_t length;
    const char* name;
};

typedef struct _Identifier Identifier;

typedef enum _ExpressionType {
    EXPR_ASSIGN,
    EXPR_STRING,
    EXPR_VAR,
    EXPR_MUT,
};

typedef enum _ExpressionType ExpressionType;

struct Expression {
   Position* pos;
   ExpressionType type;
   union {
      struct {
         Expression *left, *right;
      } assign;
      struct {
         size_t length;
         const char* name;
      } string;
      struct {
         Identifier id;
      } var;
      struct {
         Identifier id;
      } mut;
   };
};

#endif
