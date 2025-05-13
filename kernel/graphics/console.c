#include <console.h>
#include <psf.h>
#include <stdint.h>
#include <psf.h>

uint32_t width = 0;
uint32_t height = 0;

void init_console()
{
	width = 0;
	height = 0;
	
	psf_init();
}

uint32_t get_console_x()
{
	return width;
}

uint32_t get_console_y() 
{
	return height;
}