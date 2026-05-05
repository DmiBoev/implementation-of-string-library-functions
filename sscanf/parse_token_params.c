// 1. Parsing format parameters: width, length (h, l, L, ll) and the '*' flag 
#include "my_string.h"

void parse_token_params(const char** format, Token* tok) {
  if (**format == '*') {
    tok->star = 1;
    (*format)++;
  }
  while (**format >= '0' && **format <= '9') {
    tok->width = tok->width * 10 + (**format - '0');
    (*format)++;
  }
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    tok->length = **format;
    (*format)++;
    if (tok->length == 'l' && **format == 'l') {
      tok->length_double = 1;
      (*format)++;
    }
  }
}
