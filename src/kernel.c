#include "mini_uart.h"
#include "utils.h"
#include "klibc.h"

void kernel_main(void)
{
	const char core = cpu_id();
	
	uart_init();
	init_printf(0,putc);
	uart_send_string("Hello, world!\r\n");
	uart_send_string("Proc id :");
	uart_send(core + '0');
	uart_send_string("\r\n");

	while (1) 
		uart_send(uart_recv());
	 
}
