#include <sse.h>

void init_sse()
{
	asm volatile(
		"mov %%cr0, %%rax\n"
		"and $0xFFFB, %%ax\n"
		"or $2, %%eax\n"
		"mov %%rax, %%cr0\n"
		"mov %%cr4, %%rax\n"
		"or $0b11000000000, %%rax\n"
		"mov %%rax, %%cr4\n" 
		: : : "rax"
	);
}