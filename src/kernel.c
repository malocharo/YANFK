#include "mini_uart.h"
#include "utils.h"
#include "klibc.h"

void kernel_main(void)
{
	const unsigned int core = cpu_id();
	const unsigned int exception_lvl = excpt_lvl();
	
	uart_init();
	kprintf("Exception level is :%d \r\n",exception_lvl);

	while (1) 
		uart_send(uart_recv());
	 
}
