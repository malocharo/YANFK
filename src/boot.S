#include "mm.h"

.data
barrier: .byte 0
         .align 2

.section ".text.boot"

.globl _start
_start:
	bl get_id_core		// Check processor id
	cbz	x0, bss_init		// CPU #0 do BSS initialization, others wait
	

bss_init:
	// BSS Initialization
    adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero
	b master
	
proc_hang: 
	b 	proc_hang

master:
	bl get_id_core
	bl init_stack
	bl	kernel_main
	b 	proc_hang
