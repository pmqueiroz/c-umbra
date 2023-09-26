#ifndef UMBRA_AST_H
#define UMBRA_AST_H

#include "token.h"

struct UmbExpression {
   TokenType type;
   struct {
      int ln;
      int col;
   } loc;
   union {
      struct {
         TokenType* type;
         UmbExpression *left, *right;
      } assign;
      struct {
         int length;
         const char* raw;
      } string;
   } as;
};

UmbExpression* umb_assign_expression(int ln, int col, UmbExpression* left, UmbExpression* right);
UmbExpression* umb_string_literal(int ln, int col, const char* str, size_t length);
