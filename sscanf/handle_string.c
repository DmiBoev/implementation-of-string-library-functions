//6. Processing of the string case (s) 
#include "my_string.h"

int handle_string(const char** src, va_list* args, Token tok, int* count,
                  int success_match) {
  skip_spaces(src);
  if (!**src) {
    if (!success_match) *count = -1;
    return 0;
  }
  char* p = tok.star ? (void*)0 : va_arg(*args, char*);
  int rd = 0;
  while (**src && !isspace(**src) && (tok.width == 0 || rd < tok.width)) {
    if (p) *p++ = **src;
    (*src)++;
    rd++;
  }
  if (p) *p = '\0';
  return 1;
}
