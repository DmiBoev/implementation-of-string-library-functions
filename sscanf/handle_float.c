//Processing cases of fractional numbers (f, e, E, g, G)
#include "my_string.h"

int handle_float(const char** src, va_list* args, Token tok) {
  skip_spaces(src);
  long double val;
  int res = 0;
  if (parse_float(src, &val, tok.width)) {
    if (!tok.star) write_float(args, val, tok);
    res = 1;
  }
  return res;
}
