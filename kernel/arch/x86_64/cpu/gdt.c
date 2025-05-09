#include <stdint.h>
#include <gdt.h>
#include <memory.h>

#define KERNEL_STACK_SIZE 8192
uint8_t kernel_stack[KERNEL_STACK_SIZE];

struct gdt_entry_struct gdt_entries[7];
struct gdt_ptr_struct gdt_ptr;
struct tss_entry_struct tss_entry;

void init_gdt()
{
	gdt_ptr.limit = sizeof(struct gdt_entry_struct) * 7 - 1;
	gdt_ptr.base = (uint64_t)&gdt_entries;
	
	set_gdt(0,0,0,0,0); // null segment
	set_gdt(1,0,0,0x9A,0xA0); // kernel code
	set_gdt(2,0,0,0x92,0xC0); // kernel data
	set_gdt(3,0,0,0xFA,0xA0); // user code
	set_gdt(4,0,0,0xF2,0xC0); // user data
	set_tss(5,(uint64_t)&kernel_stack[KERNEL_STACK_SIZE]);
	
	gdt_flush();
	tss_flush();
}

void gdt_flush(void) 
{
    asm volatile (
        "lgdt %0\n"
        "mov $0x10, %%ax\n"
        "mov %%ax, %%ds\n"
        "mov %%ax, %%es\n"
        "mov %%ax, %%ss\n"
        "pushq $0x08\n"
        "lea 1f(%%rip), %%rax\n"
        "pushq %%rax\n"
        "lretq\n"
        "1:\n"
        : : "m"(gdt_ptr) : "rax", "memory"
    );
}

void set_gdt(uint64_t id, uint64_t base, uint64_t limit, uint8_t access, uint8_t flags)
{
	gdt_entries[id].base_low = base & 0XFFFF;
	gdt_entries[id].base_middle = (base >> 16) & 0xFF;
	gdt_entries[id].base_high = (base >> 24) & 0xFF;
	
	gdt_entries[id].limit = limit & 0xFFFF;
	gdt_entries[id].flags = (limit >> 16) & 0x0F;
	gdt_entries[id].flags |= flags & 0xF0;
	
	gdt_entries[id].access = access;
}

set_tss(uint64_t id, uint64_t rsp0)
{
	uint64_t base = (uint64_t) &tss_entry;
	uint64_t limit = sizeof(struct tss_entry_struct) - 1;
	
	set_gdt(id, base, limit, 0x89, 0x00);
	
	memset(&tss_entry, 0, sizeof(tss_entry));	
	
	tss_entry.rsp0 = rsp0;
	tss_entry.iomap = sizeof(tss_entry);
}

void tss_flush(void)
{
	asm volatile (
		"mov $0x28, %%ax\n"
		"ltr %%ax\n"
		: : : "ax"
	);
}