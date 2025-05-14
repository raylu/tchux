#ifndef FB_H
#define FB_H

#include <stdint.h>

extern uint8_t *framebuffer;
extern uint16_t framebufferWidth;
extern uint16_t framebufferHeight;
extern uint32_t framebufferPitch;

extern struct limine_framebuffer limine_fb;

void init_fb();
void draw_pixel(uint32_t x, uint32_t y, uint32_t color);
void draw_text(uint32_t x, uint32_t y, const char *text, uint32_t color);

#endif