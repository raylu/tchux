#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>

extern uint32_t width;
extern uint32_t height;

void init_console();

uint32_t get_console_x();
uint32_t get_console_y();

#endif