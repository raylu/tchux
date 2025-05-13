#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

/* Ports */
void outportb(uint16_t port, uint8_t value);
char inportb(uint16_t port);

#endif