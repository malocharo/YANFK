#ifndef	_BOOT_H
#define	_BOOT_H

extern void delay ( unsigned long); // ye.. ikn
extern void put32 ( unsigned long, unsigned int ); // write 32 bits in physical mem
extern unsigned int get32 ( unsigned long ); // read 32 bit in physical mem
extern int cpu_id();

#endif  /*_BOOT_H */
