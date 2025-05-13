#include <limine.h>
#include <stdbool.h>
#include <stddef.h>
#include <gdt.h>
#include <idt.h>
#include <fb.h>

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
	
	/* cpu */
	init_gdt();
	init_idt();
	
	/* framebuffer */
	init_fb();
	
	
	draw_text(10, 10, "Welcome to Tchux OS ", 0xFFFFFF);
	draw_text(10, 50, "GDT loaded", 0xFFFFFF);
	draw_text(10, 70, "IDT loaded", 0xFFFFFF);
	draw_text(10, 90, "Framebuffer loaded", 0xFFFFFF);
	
	hcf();
}