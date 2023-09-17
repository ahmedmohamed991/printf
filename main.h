#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define UNUSED(x) (void)(x)
#define buff 1024

/*FLAGS*/
#define fminus 1
#define fplus 2
#define fzero 4
#define fhash 8
#define fspace 16

/* SIZE*/
#define _long 2
#define _short 1
/**
 * struct fmt - struct op
 * @fmt: format
 * @fn: the function associated
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: format
 * @fm_t: function
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int _handle(const char *format, int *a, va_list l, char b[]
, int f, int w, int s, int p);
int _char(va_list t, char b[],
int f, int w, int p, int s);
int _string(va_list t, char b[], int f, int w, int p, int s);
int _percent(va_list t, char b[],
int f, int w, int s);
int _int(va_list t, char b[],
int f, int w, int p, int s);
int _binary(va_list t, char b[],
int f, int w, int p, int s);
int _unsigned(va_list t, char b[],
int f, int w, int p, int s);
int _octal(va_list t, char b[],
int f, int s, int w, int p);
int _hexa(va_list t, char b[],
int f, int w, int s, int p);
int _haexau(va_list t, char b[],
int f, int w, int s, int p);
int _h(va_list t, char ma[],
char b[], int f, char fc, int w, int p, int s);
int _nonprint(va_list t, char b[],
int f, int w, int s, int p);
int _pointer(va_list t, char b[],
int f, int w, int p, int s);
int _flags(const char *format, int *a);
int _width(const char *s, int *a, va_list l);
int _precision(const char *f, int *a, va_list l);
int _size(const char *f, int *a);
int _reverse(va_list t, char b[],
int f, int w, int s, int p);
int _rot(va_list t, char b[],
int f, int w, int s, int p);

int _writechar(char c, char b[],
int f, int w, int p, int s);
int _numbers(int _positive, int d, char b[],
int f, int w, int p, int s);
int _num(int d, char b[], int f, int w, int p, int l, char pa, char ec);
int _wpointer(char c[], int d, int l,
int w, int f, char, pa, char ec, int pas);
int _unsgnd(int _negative, int d,
char b[], int f, int w, int s, int p);
int _printable(char);
int a_hexa(char, char[], int);
int _digit(char);
long int _size(long int n, int s);
long int _convert(unsigned long int n, int s);
#endif
