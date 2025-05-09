#ifndef GDT_H
#define GDT_H

#include <stdint.h>

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

struct tss_entry_struct
{
	uint64_t reserved0;
	uint64_t rsp0;
	uint64_t rsp1;
	uint64_t rsp2;
	uint64_t reserved1;
	uint64_t ist1;
	uint64_t ist2;
	uint64_t ist3;
	uint64_t ist4;
	uint64_t ist5;
	uint64_t ist6;
	uint64_t ist7;
	uint64_t reserved2;
	uint64_t reserved3;
	uint64_t iomap;
}__attribute__((packed));

void init_gdt();
void set_gdt(uint64_t id, uint64_t base, uint64_t limit, uint8_t access, uint8_t flags);
void set_tss(uint64_t id, uint64_t rsp0);

#endif