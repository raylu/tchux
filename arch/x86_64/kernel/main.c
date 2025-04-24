#include <limine.h>

__attribute__((used, section(".limine_requests")))
static volatile LIMINE_BASE_REVISION(3);

void kmain(void)
{	
	for(;;)
	{
		__asm__("hlt");
	}
}