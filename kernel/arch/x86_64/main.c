#include <limine.h>
#include <stdbool.h>
#include <stddef.h>
#include <gdt.h>
#include <idt.h>



static void hcf(void)
{
	for(;;)
	{
		__asm__("hlt");
	}
}

static volatile LIMINE_BASE_REVISION(3);
void kmain(void)
{	
	if (LIMINE_BASE_REVISION_SUPPORTED == false)
	{
		hcf();
	}
	
	init_gdt();
	init_idt();
	hcf();
}