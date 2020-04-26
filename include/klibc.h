#ifndef _KLIBC_H
#define _KLIBC_H
#include "mini_uart.h"
#include <stdarg.h>

int kprintf(char* fmt,...);

int convert(int number, int base);
void reverse_str(char* str, int len);
void print_buffer(char* str);
#endif
