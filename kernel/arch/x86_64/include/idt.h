#ifndef IDT_H
#define IDT_H

#include <stdint.h>

struct idt_entry_struct
{
	uint16_t base_low;
	uint16_t ss;
	uint8_t ist;
	uint8_t flags;
	uint16_t base_mid;
	uint32_t base_high;
	uint32_t reserved;
} __attribute__((packed));

struct idt_ptr_struct
{
	uint16_t limit;
	uint64_t base;
} __attribute__((packed));

void init_idt();
void set_idt(uint8_t id, uint64_t handler, uint8_t flags);

#endif