#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

void draw_pixel(int32_t x, int32_t y, uint8_t r, uint8_t  g, uint8_t  b);
void draw_rect(int32_t x, int32_t y, int32_t w, int32_t h, uint8_t r, uint8_t g, uint8_t b);

#endif