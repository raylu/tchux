#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>

/* Recive Data */
uint32_t serial_recived();
char read_serial();

/* Send Data */
uint32_t is_transmit_empty();
void serial_putc(char c);
void serial_write(char *str);

#endif