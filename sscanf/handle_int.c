//Processing integer cases (d, i, u, o, x, p)
#include "my_string.h"

int handle_int(const char** src, va_list* args, Token tok, char spec) {
  propusk_simvols(src);
  unsigned long long val;
  int base = (spec == 'o')                                 ? 8
             : (spec == 'x' || spec == 'X' || spec == 'p') ? 16
             : (spec == 'i')                               ? 0
                                                           : 10;
  int res = 0;
  if (parse_uint(src, &val, base, tok.width)) {
    if (!tok.star) write_integer(args, val, tok, spec);
    res = 1;
  }
  return res;
}
