#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>

/* init serial */
void serial_enable(uint32_t device);
void init_serial();

/* Recive Data */
uint32_t serial_recived();
char read_serial();

/* Send Data */
uint32_t is_transmit_empty();
void serial_putc(char c);
void serial_write(char *str);

#endif