#include <serial.h>
#include <stdint.h>
#include <ports.h>

/* Recive Data */
uint32_t serial_recived()
{
	return inportb(0x3f8 + 5) & 1;
}

char read_serial()
{
	while (serial_recived() == 0);
	return inportb(0x3f8);
}

/* Send Data */
uint32_t is_transmit_empty()
{
	return inportb(0x3f8 + 5) & 0x20;
}

void serial_putc(char c)
{
	while (is_transmit_empty() == 0);
	outportb(0x3f8, c);
}

void serial_write(char *str)
{	
	for (uint64_t i = 0; str[i]; i++)
	{
		serial_putc(str[i]);
	}
}