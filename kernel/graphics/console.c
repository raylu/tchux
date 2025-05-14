#include <console.h>
#include <stdint.h>

uint32_t width = 0;
uint32_t height = 0;

void init_console()
{
	width = 0;
	height = 0;
}

uint32_t get_console_x()
{
	return width;
}

uint32_t get_console_y() 
{
	return height;
}