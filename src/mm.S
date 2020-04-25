#include "mm.h"
.globl memzero
memzero:
	str xzr, [x0], #8
	subs x1, x1, #8
	b.gt memzero
	ret

.globl get_id_core
get_id_core:
	mrs	x0, mpidr_el1		// Primary CPU has id 0x0
	and	x0, x0,#0xFF
	ret

.globl init_stack
init_stack:
	mov x1, #STACK_OFFSET //1kb per stack per proc
	mul x0,x0, x1
	add x0, x0, #LOW_MEMORY
	mov sp, x0	
	ret
