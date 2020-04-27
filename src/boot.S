#include "mm.h"
#include "arm/sysreg.h"

.data
barrier: .byte 0
         .align 2

.section ".text.boot"

.globl _start
_start:
	bl get_id_core		// Check processor id
	cbz	x0, excpt		// CPU #0 do BSS initialization, others wait
	b proc_hang

excpt:
	ldr	x0, =SCTLR_VALUE_MMU_DISABLED
	msr	sctlr_el1, x0

	ldr	x0, =HCR_VALUE
	msr	hcr_el2, x0

	ldr	x0, =SPSR_VALUE
	msr	spsr_el2, x0

	adr	x0, bss_init
	msr	elr_el2, x0

	eret

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
