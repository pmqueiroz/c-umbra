#include "../include/tokenizer.h"
#include <stdio.h>

static TokenType get_instance(const char* buf) {
   if (strcmp(buf, "mut") == 0)
      return MUTABLE__KEYWORD;
   if (strcmp(buf, "str") == 0)
      return STRING_TYPE__KEYWORD;
   if (strcmp(buf, "num") == 0)
      return NUMBER_TYPE__KEYWORD;
   if (strcmp(buf, "package") == 0)
      return MODULE_DEF__KEYWORD;
   if (strcmp(buf, "mut") == 0)
      return MUTABLE__KEYWORD;
   return UNKNOWN__KEYWORD;
}

static TokenType get_operator(const char* buf) {
   if (strcmp(buf, "<-") == 0)
      return ASSIGNMENT__OPERATOR;
   if (strcmp(buf, "#") == 0)
      return COMMENT__OPERATOR;
   return UNKNOWN__KEYWORD;
}

static void push_token(TokenList* list, char* value, int line) {
   TokenType type;

   TokenType instance_attempt = get_instance(value);

   if (instance_attempt != UNKNOWN__KEYWORD) {
      type = instance_attempt;
   } else {
      TokenType operator_attempt = get_operator(value);

         if (operator_attempt != UNKNOWN__KEYWORD) {
            type = operator_attempt;
         } else {
            type = IDENTIFIER__KEYWORD;
         }
   }

   token_list_add(list, token_create(type, value, line));
}

void generate_tokens(char* code, TokenList* list) {
   char lexeme[256];
   int lexi = 0;
   int i = 0;
   int line = 1;
   int curr_ignored_line = -1;

   while (1) {
      while (code[i] != '\n' && code[i] != '\0') {
         if (code[i] == '#') {
            curr_ignored_line = line;
            i++;
            continue;
         }

         if (code[i] == ' ' && curr_ignored_line != line) {
            break;
         }
         
         if (curr_ignored_line != line) {
            lexeme[lexi++] = code[i++];
         } else {
            i++;
         }
      }

      // new line
      if (code[i] == '\n') {
         line++;
      }
      
      // eof
      if (code[i] == '\0') {
         break;
      }

      lexeme[lexi] = '\0';

      push_token(list, lexeme, line);

      lexi = 0;
      i++;
   }
}
