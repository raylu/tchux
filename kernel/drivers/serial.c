#include <serial.h>
#include <stdint.h>
#include <ports.h>

void serial_enable(uint32_t device)
{
	outportb(device + 1, 0x00);
	outportb(device + 3, 0x80);
	outportb(device + 0, 0x03);
	outportb(device + 1, 0x00);
	outportb(device + 3, 0x03);
	outportb(device + 2, 0xC7);
	outportb(device + 4, 0x0B);
}

void init_serial()
{
	serial_enable(0x3f8);
	outportb(0x3f8 + 1, 0x01);
	
}

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