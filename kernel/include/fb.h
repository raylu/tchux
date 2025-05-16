#ifndef FB_H
#define FB_H

#include <stdint.h>

extern uint8_t *framebuffer;
extern uint16_t framebuffer_width;
extern uint16_t framebuffer_height;
extern uint32_t framebuffer_pitch;

extern struct limine_framebuffer limine_fb;

void init_fb();
void draw_pixel(uint32_t x, uint32_t y, uint32_t color);
void draw_text(uint32_t x, uint32_t y, const char *text, uint32_t color);

#endif