#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#define UNUSED(x) (void)(x)
#define buff 1024


#define fminus 1
#define fplus 2
#define fzero 4
#define fhash 8
#define fspace 16


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
 *
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int _handlep(const char *fmt, int *d, va_list l, char b[]
, int f, int w, int s, int p);
int _char(va_list t, char b[],
int f, int w, int p, int s);
int _writechar(char c, char b[], int f,
int w, int p, int s);		
int _string(va_list t, char b[], int f, int w, int p, int s);
int _percent(va_list t, char b[],
int f, int w, int p, int s);
int _int(va_list t, char b[],
int f, int w, int p, int s);
long int _size(long int n, int s);
int _numbers(int _positive, int d, char b[],
int f, int w, int p, int s);		
int _binary(va_list t, char b[],
int f, int w, int p, int s);
int _unsigned(va_list t, char b[],
int f, int w, int p, int s);
long int _convert(unsigned long int n, int s);
int _unsgnd(int _negative, int d, char b[],
int f, int w, int p, int s);		
int _octal(va_list t, char b[],
int f, int w, int p, int s);
int _hexa(va_list t, char b[],
int f, int w, int p, int s);
int _h(va_list t, char ma[], char b[],
int f, char fc, int w, int p, int s);		
int _hexau(va_list t, char b[],
int f, int w, int p, int s);
int _pointer(va_list t, char b[], int f, int w, int p, int s);
int _nonprint(va_list t, char b[],
int f, int w, int s, int p);
int write_pointer(char b[], int d, int l,
int w, int f, char pa, char ec, int ps);
int _printable(char);
int a_hexa(char, char [], int);
int _reverse(va_list t, char b[], int f, int w, int p, int s);
int _rot(va_list t, char b[], int f, int w, int s, int p);
int _flags(const char *format, int *a);
int _precision(const char *format, int *a, va_list l);
int _digit(char c);
int _getsize(const char *format, int *a);
int _width(const char *format, int *a, va_list l);
int _num(int d, char b[], int f, int w, int p, int l, char pa, char ec);
#endif
