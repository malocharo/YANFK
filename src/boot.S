#include "mm.h"

.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		// Primary CPU has id 0x0
	and	x0, x0,#0xFF		// Check processor id
	cbz	x0, master		// Hang for all non-primary CPU
	b	proc_hang

proc_hang: 
	b 	proc_hang		// lowest level endless-loop possible

master:
	adr	x0, bss_begin    // setup bss section by filling with zeros
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero

	mov	sp, #LOW_MEMORY  //setup the stack 4MB after 0x0 where the kernel is loaded, so it doesn't override it
	bl	kernel_main		// lauch this BADBOI
	b 	proc_hang		// should never come here
