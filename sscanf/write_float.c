//3. Writing floating-point numbers to arguments
#include "my_string.h"
void write_float(va_list* args, long double val, Token tok) {
  if (tok.length == 'L')
    *(va_arg(*args, long double*)) = val;
  else if (tok.length == 'l')
    *(va_arg(*args, double*)) = (double)val;
  else
    *(va_arg(*args, float*)) = (float)val;
}
