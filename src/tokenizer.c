#include "../include/tokenizer.h"
#include <stdio.h>

int get_one_char_operator(int c1) {
   switch (c1) {
      case '#':
         return COMMENT__OPERATOR;
         break;
      case '(':
         return OPEN_BRACKETS__OPERATOR;
         break;
      case ')':
         return CLOSE_BRACKETS__OPERATOR;
         break;
      case '{':
         return OPEN_CURLY_BRACES__OPERATOR;
         break;
      case '}':
         return CLOSE_CURLY_BRACES__OPERATOR;
         break;
      default:
         return UNKNOWN__KEYWORD;
         break;
   }
}

int get_two_char_operator(int c1, int c2) {
   switch (c1) {
      case '<':
         switch (c2) {
            case '-':
               return ASSIGNMENT__OPERATOR;
         }
         break;
      default:
         return UNKNOWN__KEYWORD;
         break;
   }
}

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
   int len = get_lexeme_length(buf);

   switch (len) {
      case 1:
         return get_one_char_operator(buf[0]);
         break;
      case 2:
         return get_two_char_operator(buf[0], buf[1]);
         break;
      case 3:
         return UNKNOWN__KEYWORD; // todo get_three_char_operator;
         break;
      default:
         return UNKNOWN__KEYWORD;
         break;
   }

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

static int is_statement_operator(char c) { return c == '{' || c == '(' || c == ')' || c == '}'; }

void generate_tokens(char* code, TokenList* list) {
   char lexeme[256];
   int  lexi              = 0;
   int  i                 = 0;
   int  line              = 1;
   int  curr_ignored_line = -1;
   int  is_string         = 0;

   while (1) {
      while (code[i] != '\n' && code[i] != '\0') {
         if (code[i] == '#') {
            curr_ignored_line = line;
            i++;
            continue;
         }

         if (code[i] == '"' || code[i] == '\'') {
            toggle_bool(&is_string);
         }

         if (code[i] == ' ' && curr_ignored_line != line && !is_string) {
            break;
         }

         if (is_statement_operator(code[i + 1])) {
            lexeme[lexi++] = code[i++];
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

      if (lexeme[0] != '\0') {
         push_token(list, lexeme, line);
      }

      lexi = 0;
      i++;
   }
}
