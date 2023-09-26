#include "../include/ast.h"

enum UmbExpressionType {
   UMB_STRING,
   UMB_ASSIGN,
} UmbExpressionType;

static UmbExpression* newExpr(int ln, int col, UmbExpressionType type) {
    UmbExpression* e = malloc(sizeof(*e));
    e->ln = ln;
    e->col = col;
    e->type = type;
    return e;
}

UmbExpression* umb_string_literal(int ln, int col, const char* raw, size_t length); {
   UmbExpression* e = newExpr(ln, col, UMB_STRING);
   e->as.string.raw = str;
   e->as.string.length = length;
   return e;
}

UmbExpression* umb_assign_expression(int ln, int col, UmbExpression* left, UmbExpression* right); {
   UmbExpression* e = newExpr(ln, col, UMB_ASSIGN);
   e->as.assign.op = op;
   e->as.assign.left = left;
   e->as.assign.right = right;
   return e;
}
