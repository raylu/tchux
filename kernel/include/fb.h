#ifndef FB_H
#define FB_H

#include <stdint.h>

struct framebuffer_struct 
{
	uint8_t *addr;
	uint64_t width;
	uint64_t height;
	uint64_t pitch;
	uint64_t bpp;
	
	uint64_t red_shift;
	uint64_t red_size;
	uint64_t green_shift;
	uint64_t green_size;
	uint64_t blue_shift;
	uint64_t blue_size;
};

extern struct framebuffer_struct framebuffer;
extern struct limine_framebuffer limine_fb;

void init_fb();

#endif