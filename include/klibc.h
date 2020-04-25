#ifndef _KLIBC_H
#define _KLIBC_H
#include <stdarg.h>

void init_printf(void* putp,void (*putf) (void*,char));

void tfp_printf(char *fmt, ...);
void tfp_sprintf(char* s,char *fmt, ...);

void tfp_format(void* putp,void (*putf) (void*,char),char *fmt, va_list va);

#define kprintf tfp_printf
#define ksprintf tfp_sprintf

#endif // _KLIBC_H