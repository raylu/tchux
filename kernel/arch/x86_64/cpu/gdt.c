#include <stdint.h>
#include <gdt.h>

struct gdt_entry_struct gdt_entries[6];
struct gdt_ptr_struct gdt_ptr;

void init_gdt()
{
	gdt_ptr.limit = sizeof(struct gdt_entry_struct) * 6 - 1;
	gdt_ptr.base = (uint64_t)&gdt_entries;
	
	set_gdt(0,0,0,0,0); // null segment
	set_gdt(1,0,0,0x9A,0xA0); // kernel code
	set_gdt(2,0,0,0x92,0xC0); // kernel data
	set_gdt(3,0,0,0xFA,0xA0); // user code
	set_gdt(4,0,0,0xF2,0xC0); // user data
	
	gdt_flush();
}

void gdt_flush(void) {
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

void set_gdt(uint64_t num, uint64_t base, uint64_t limit, uint8_t access, uint8_t flags)
{
	gdt_entries[num].base_low = base & 0XFFFF;
	gdt_entries[num].base_middle = (base >> 16) & 0xFF;
	gdt_entries[num].base_high = (base >> 24) & 0xFF;
	
	gdt_entries[num].limit = limit & 0xFFFF;
	gdt_entries[num].flags = (limit >> 16) & 0x0F;
	gdt_entries[num].flags |= flags & 0xF0;
	
	gdt_entries[num].access = access;
	
}