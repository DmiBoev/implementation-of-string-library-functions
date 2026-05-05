#include "my_string.h"

unsigned long get_unsigned_arg(va_list* args, format fmt) {
  unsigned long value = 0;
  if (fmt.length == 'h') {
    value = (unsigned short)va_arg(*args, unsigned int);
  } else if (fmt.length == 'l') {
    value = va_arg(*args, unsigned long);
  } else {
    value = va_arg(*args, unsigned int);
  }
  return value;
}
