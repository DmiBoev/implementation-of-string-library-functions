#include "my_string.h"

long get_signed_arg(va_list* args, format fmt) {
  long value = 0;
  if (fmt.length == 'h') {
    value = (short)va_arg(*args, int);
  } else if (fmt.length == 'l') {
    value = va_arg(*args, long);
  } else {
    value = va_arg(*args, int);
  }
  return value;
}
