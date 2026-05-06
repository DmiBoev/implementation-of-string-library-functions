#ifndef STRING_H
#define STRING_H

#include <ctype.h>
#include <stdarg.h>
#include <stddef.h>

typedef struct {
  int star;
  int width;
  int length_double;
  char length;
} Token;

typedef struct {
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int width;
  int precision;
  int precision_set;
  char length;
  char spec;
} format;

typedef size_t my_size;

void *memchr(const void *str, int c, s21_size n);
int memcmp(const void *str1, const void *str2, my_size n);
void *memcpy(void *dest, const void *src, my_size n);
void *memset(void *str, int c, my_size n);

void apply_string_precision(char *buffer, format fmt);
void long_to_str(long num, char *buffer);
void apply_int_sign(char *buffer, format fmt);
void apply_int_precision(char *buffer, format fmt);
void apply_alt_form(char *buffer, format fmt, unsigned long num);
void apply_pointer_prefix(char *buffer);

char *strncat(char *dest, const char *src, size n);
char *strchr(const char *str, int c);
int strncmp(const char *str1, const char *str2, size n);
char *strncpy(char *dest, const char *src, size n);
s21_size strcspn(const char *str1, const char *str2);
char *strerror(int errnum);
s21_size strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);
void ulong_to_str(unsigned long num, char *str);
void general_to_str(long double num, char *str, format fmt);
int sprintf(char *str, const char *format, ...);
int get_exp(long double num);
unsigned long get_unsigned_arg(va_list *args, format fmt);
int sscanf(const char *src, const char *format, ...);
long get_signed_arg(va_list *args, format fmt);
int get_digit(char c, int base);
void propusk_simvols(const char **src);
int parse_uint(const char **src, unsigned long long *dest, int base, int width);
int parse_float(const char **src, long double *dest, int width);
void handle_specifier(const char **src, const char *start, va_list *args,
                      Token tok, char spec, int *count, int *success_match,
                      int *break_flag);
void parse_token_params(const char **format, Token *tok);
void write_integer(va_list *args, unsigned long long val, Token tok, char spec);
void write_float(va_list *args, long double val, Token tok);
int handle_int(const char **src, va_list *args, Token tok, char spec);
int handle_float(const char **src, va_list *args, Token tok);
int handle_string(const char **src, va_list *args, Token tok, int *count,
                  int success_match);
int handle_char(const char **src, va_list *args, Token tok);
format init_format(void);
void *insert(const char *src, const char *str, size start_index);
void *to_lower(const char *str);
void *to_upper(const char *str);
void *trim(const char *src, const char *trim_chars);
int s21_is_digit(char c);
const char *s21_parse_format(const char *format, format *fmt,
                             va_list *args);
void ulong_to_str(unsigned long num, char *str);
void remove_trailing_zeros(char *str);
void ulong_to_base(unsigned long num, char *str, int base, int uppercase);
void scientific_to_str(long double num, char *str, format fmt);
char *write_with_width(char *str, const char *buffer, format fmt);
void float_to_str(long double num, char *str, format fmt);
void exp_to_str(int exp, char *str, int uppercase);
#endif
