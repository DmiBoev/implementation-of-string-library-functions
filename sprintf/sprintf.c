#include "my_string.h"

int my_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);
  char* start = str;
  while (*format != '\0') {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
    } else {
      format++;
      format fmt = init_format();
      format = parse_format(format, &fmt, &args);
      if (fmt.spec == '%') {
        *str = '%';
        str++;
      } else if (fmt.spec == 'c') {
        char buffer[2];
        buffer[0] = (char)va_arg(args, int);
        buffer[1] = '\0';
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 's') {
        char* s = va_arg(args, char*);
        char buffer[1000];
        int i = 0;
        while (s && s[i] != '\0') {
          buffer[i] = s[i];
          i++;
        }
        buffer[i] = '\0';
        apply_string_precision(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'd' || fmt.spec == 'i') {
        long num = get_signed_arg(&args, fmt);
        char buffer[100];
        long_to_str(num, buffer);
        apply_int_sign(buffer, fmt);
        apply_int_precision(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'u') {
        unsigned long num = get_unsigned_arg(&args, fmt);
        char buffer[100];
        ulong_to_str(num, buffer);
        apply_int_precision(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'x' || fmt.spec == 'X') {
        unsigned long num = get_unsigned_arg(&args, fmt);
        char buffer[100];
        ulong_to_base(num, buffer, 16, fmt.spec == 'X');
        apply_int_precision(buffer, fmt);
        apply_alt_form(buffer, fmt, num);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'o') {
        unsigned long num = get_unsigned_arg(&args, fmt);
        char buffer[100];
        ulong_to_base(num, buffer, 8, 0);
        apply_int_precision(buffer, fmt);
        apply_alt_form(buffer, fmt, num);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'f') {
        long double num;
        if (fmt.length == 'L')
          num = va_arg(args, long double);
        else
          num = va_arg(args, double);
        char buffer[200];
        float_to_str(num, buffer, fmt);
        apply_int_sign(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'e' || fmt.spec == 'E') {
        long double num;
        if (fmt.length == 'L')
          num = va_arg(args, long double);
        else
          num = va_arg(args, double);
        char buffer[250];
        scientific_to_str(num, buffer, fmt);
        apply_int_sign(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'g' || fmt.spec == 'G') {
        long double num;
        if (fmt.length == 'L')
          num = va_arg(args, long double);
        else
          num = va_arg(args, double);
        char buffer[250];
        general_to_str(num, buffer, fmt);
        apply_int_sign(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      } else if (fmt.spec == 'n') {
        int* count_ptr = va_arg(args, int*);
        if (count_ptr) *count_ptr = str - start;
      } else if (fmt.spec == 'p') {
        void* ptr = va_arg(args, void*);
        unsigned long num = (unsigned long)ptr;
        char buffer[100];
        ulong_to_base(num, buffer, 16, 0);
        apply_pointer_prefix(buffer);
        apply_int_sign(buffer, fmt);
        str = write_with_width(str, buffer, fmt);
      }
    }
  }

  *str = '\0';
  va_end(args);
  return str - start;
}
