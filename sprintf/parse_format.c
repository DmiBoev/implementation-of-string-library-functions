#include "my_string.h"

const char* parse_format(const char* format, my_format* fmt,
                             va_list* args) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    if (*format == '-') fmt->minus = 1;
    if (*format == '+') fmt->plus = 1;
    if (*format == ' ') fmt->space = 1;
    if (*format == '#') fmt->sharp = 1;
    if (*format == '0') fmt->zero = 1;
    format++;
  }

  if (*format == '*') {
    fmt->width = va_arg(*args, int);
    format++;
  } else {
    while (is_digit(*format)) {
      fmt->width = fmt->width * 10 + (*format - '0');
      format++;
    }
  }

  if (*format == '.') {
    fmt->precision_set = 1;
    format++;

    if (*format == '*') {
      fmt->precision = va_arg(*args, int);
      format++;
    } else {
      while (is_digit(*format)) {
        fmt->precision = fmt->precision * 10 + (*format - '0');
        format++;
      }
    }
  }

  if (*format == 'h' || *format == 'l' || *format == 'L') {
    fmt->length = *format;
    format++;
  }
  fmt->spec = *format;
  if (*format != '\0') {
    format++;
  }
  return format;
}
