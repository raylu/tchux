#include <stdint.h>

#ifndef GDT_H
#define GDT_H

struct gdt_entry_struct 
{
	uint16_t limit;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t flags;
	uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr_struct
{
	uint16_t limit;
	uint64_t base;
} __attribute__((packed));

void init_gdt();
void set_gdt(uint64_t id, uint64_t base, uint64_t limit, uint8_t access, uint8_t flags);

#endif