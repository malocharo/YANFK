.globl put32
put32:
	str w1,[x0]
	ret

.globl get32
get32:
	ldr w0,[x0]
	ret

.globl delay
delay:
	subs x0, x0, #1
	bne delay
	ret
.globl cpu_id
cpu_id:
	mrs	x0, mpidr_el1		// Primary CPU has id 0x0
	and	x0, x0,#0xFF
	ret

.globl excpt_lvl
excpt_lvl:
	mrs x0, CurrentEL
	lsr x0, x0, #2 //cuz first 2 bits always zero
	ret