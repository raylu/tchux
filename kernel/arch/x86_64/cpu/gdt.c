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
	set_gdt(2,0,0,0x92,0xA0); // kernel data
	set_gdt(3,0,0,0xFA,0xA0); // user code
	set_gdt(4,0,0,0xF2,0xA0); // user data
	
	asm("lgdt %0" : : "m" (gdt_ptr));
	
	asm volatile(
		"\
			push $0x08; \
			lea reload(%%rip), %%rax; \
			push %%rax; \
			lretq; \
			reload: \
			mov $0x10, %%ax; \
			mov %%ax, %%ds; \
			mov %%ax, %%es; \
			mov %%ax, %%fs; \
			mov %%ax, %%gs; \
			mov %%ax, %%ss" : : : "eax", "rax"
	);
}

void set_gdt(uint64_t num, uint64_t base, uint64_t limit, uint8_t access, uint8_t flags)
{
	gdt_entries[num].base_low = base & 0XFFFF;
	gdt_entries[num].base_middle = (base >> 16) & 0xFF;
	gdt_entries[num].base_high = (base >> 24) & 0xFF;
	
	gdt_entries[num].limit = limit & 0xFFFF;
	gdt_entries[num].flags = (limit >> 16) & 0x0F;
	gdt_entries[num].flags = (flags << 4) & 0xF0;
	
	gdt_entries[num].access = access;
	
}