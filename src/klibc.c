#include "klibc.h"


const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void print_buffer(char* str){
    for(char c = *str;*str;c = *(++str))
        putc(c);
}

void reverse_str(char* str, int len){
    char t;
    int t_len = len;
    for (int c = 0; c < t_len/2; c++) {
    t          = str[c];
    str[c]   = str[len-1];
    str[len-1] = t;

    len--;
  }
}

int print_base_integer(int number, int base)
{
    int abs_number =  number;
    char str[32];
    if (number < 0)
    {
         putc('-');
         abs_number = number * -1;
    }
    int i = 0;
    do
    {
        str[i] = digits[abs_number % (base )];
        abs_number /= base;
        i++;
    } while (abs_number);
    str[i+1] = '\0';
    reverse_str(str,i);
    print_buffer(str);
    return i;
}




int kprintf(char* fmt,...){
    va_list va;
    va_start(va,fmt);
    while(*fmt){
        if(*fmt == '%')
        {
            fmt++; //get next char
            if(*fmt == 'd'){
                int a = va_arg(va,int);
                print_base_integer(a,10);
            } else if(*fmt == 'h'){
                int a = va_arg(va,int);
                print_base_integer(a,16);
            } else if(*fmt == 'c'){
                char c = (char)va_arg(va,int);
                putc(c);
            } else if(*fmt == 's'){
                char *str = va_arg(va,char*);
                print_buffer(str);
            } else{
                return -1;
            }
            fmt++;
        }
        else {
            putc(*fmt);
            fmt++;
        }
    }
    va_end(va);
    return 0;
}