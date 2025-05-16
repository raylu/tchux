#ifndef FB_H
#define FB_H

#include <stdint.h>

struct framebuffer_struct 
{
	uint8_t *addr;
	uint32_t width;
	uint32_t height;
	uint32_t pitch;
	uint32_t bpp;
};

extern struct framebuffer_struct framebuffer;
extern struct limine_framebuffer limine_fb;

void init_fb();

#endif