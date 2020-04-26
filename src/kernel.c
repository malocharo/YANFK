#include "mini_uart.h"
#include "utils.h"
#include "klibc.h"

void kernel_main(void)
{
	const int core = cpu_id();
	
	uart_init();
	kprintf("Proc id:%d \r\n",core);

	while (1) 
		uart_send(uart_recv());
	 
}
