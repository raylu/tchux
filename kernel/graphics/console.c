#include <console.h>
#include <stdint.h>
#include <psf.h>

uint32_t width = 0;
uint32_t height = 0;

void init_console()
{
	width = 0;
	height = 0;
	
	load_default_font();
	draw_text(10, 10, "Tchux OS", 0xFFFFFFFF);
	draw_text(10, 25, "Copyright (C) Francisco Araujo", 0xFFFFFFFF);
}
	
uint32_t get_console_x()
{
	return width;
}

uint32_t get_console_y() 
{
	return height;
}