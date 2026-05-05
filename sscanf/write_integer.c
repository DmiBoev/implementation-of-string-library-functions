//2. Writing integer values ​​to arguments taking into account types
#include "my_string.h"
void write_integer(va_list* args, unsigned long long val, Token tok,
                   char spec) {
  if (spec == 'p') {
    *(va_arg(*args, void**)) = (void*)val;
  } else if (spec == 'u') {
    if (tok.length_double)
      *(va_arg(*args, unsigned long long*)) = (unsigned long long)val;
    else if (tok.length == 'l')
      *(va_arg(*args, unsigned long*)) = (unsigned long)val;
    else if (tok.length == 'h')
      *(va_arg(*args, unsigned short*)) = (unsigned short)val;
    else
      *(va_arg(*args, unsigned int*)) = (unsigned int)val;
  } else {
    if (tok.length_double)
      *(va_arg(*args, long long*)) = (long long)val;
    else if (tok.length == 'l')
      *(va_arg(*args, long*)) = (long)val;
    else if (tok.length == 'h')
      *(va_arg(*args, short*)) = (short)val;
    else
      *(va_arg(*args, int*)) = (int)val;
  }
}
