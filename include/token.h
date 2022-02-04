#ifndef UMBRA_TOKEN_H
#define UMBRA_TOKEN_H

#include <stdlib.h>
#include <string.h>

enum _TokenType {
   UNKNOWN__KEYWORD = -1,
   IDENTIFIER__KEYWORD,
   MUTABLE__KEYWORD,             // mut
   STRING_TYPE__KEYWORD,         // str
   NUMBER_TYPE__KEYWORD,         // num
   MODULE_DEF__KEYWORD,          // package
   ASSIGNMENT__OPERATOR,         // <-
   COMMENT__OPERATOR,            // #
   OPEN_BRACKETS__OPERATOR,      // (
   CLOSE_BRACKETS__OPERATOR,     // )
   OPEN_CURLY_BRACES__OPERATOR,  // {
   CLOSE_CURLY_BRACES__OPERATOR, // }
   NOT__OPERATOR,                // !
   AND__OPERATOR,                // &
   OR__OPERATOR,                 // |
   PLUS__OPERATOR,               // +
   MINUS__OPERATOR,              // -
   STAR__OPERATOR,               // *
   SLASH__OPERATOR,              // /
   PERCENT__OPERATOR,            // %
   EQUAL__OPERATOR,              // ==
   NOT_EQUAL__OPERATOR,          // !=
   PLUS_EQUAL__OPERATOR,         // +=
   MINUS_EQUAL__OPERATOR,        // -=
   STAR_EQUAL__OPERATOR,         // *=
   SLASH_EQUAL__OPERATOR,        // /=
};

typedef enum _TokenType TokenType;

static inline char* get_token_type_name(TokenType type) {
   char* strings[] = {
       "UNKNOWN__KEYWORD",
       "IDENTIFIER__KEYWORD",
       "MUTABLE__KEYWORD",
       "STRING_TYPE__KEYWORD",
       "NUMBER_TYPE__KEYWORD",
       "MODULE_DEF__KEYWORD",
       "ASSIGNMENT__OPERATOR",
       "COMMENT__OPERATOR",
       "OPEN_BRACKETS__OPERATOR",
       "CLOSE_BRACKETS__OPERATOR",
       "OPEN_CURLY_BRACES__OPERATOR",
       "CLOSE_CURLY_BRACES__OPERATOR"
       "NOT__OPERATOR",
       "AND__OPERATOR",
       "OR__OPERATOR",
       "PLUS__OPERATOR",
       "MINUS__OPERATOR",
       "STAR__OPERATOR",
       "SLASH__OPERATOR",
       "PERCENT__OPERATOR",
       "EQUAL__OPERATOR",
       "NOT_EQUAL__OPERATOR",
       "PLUS_EQUAL__OPERATOR",
       "MINUS_EQUAL__OPERATOR",
       "STAR_EQUAL__OPERATOR",
       "SLASH_EQUAL__OPERATOR",
   };

   return strings[type + 1];
}

struct _Token {
   TokenType type;
   char*     value;
   int       line;
};

typedef struct _Token Token;

Token* token_create(int type, char* value, int line);
void   token_destroy(Token* token);

struct _TokenList {
   Token** value;
   int     ptr;
   int     size;
};

typedef struct _TokenList TokenList;

void   token_list_add(TokenList* list, Token* token);
Token* token_list_get(TokenList* list, int index);

#endif
