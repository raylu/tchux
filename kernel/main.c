#include <limine.h>
#include <stdbool.h>
#include <stddef.h>
#include <gdt.h>
#include <idt.h>
#include <fb.h>
#include <console.h>
#include <serial.h>

static void hcf(void)
{
	for(;;)
	{
		asm volatile("hlt");
	}
}

static volatile LIMINE_BASE_REVISION(3);
void kmain(void)
{	
	if (LIMINE_BASE_REVISION_SUPPORTED == false)
	{
		hcf();
	}
	
	init_serial();
	
	/* framebuffer */
	init_fb();
	init_console();
	
	/* cpu */
	init_gdt();
	init_idt();
	
	serial_putc('a');
	
	hcf();
}