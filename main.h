#ifndef MAIN_H

#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/*flag modifiers*/
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/*length modifiers*/
#define SHORT 1
#define LONG 2

typedef struct buffer_s
{
char *buffer;
char *start;
unsigned int len;
} buffer_t;

typedef struct converter_s
{
unsigned char specifier;
unsigned int (*func)(va_list, buffer_t *, unsigned char, int, int, unsigned char);
} converter_t;

typedef struct flag_s
{
unsigned char flag;
unsigned char value;
} flag_t;

int _printf(const char *format, ...);

/*conversion specifiers*/
unsigned int convert_c(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);

unsigned int convert_s(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);

unsigned int convert_di(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);

unsigned int convert_percent(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
