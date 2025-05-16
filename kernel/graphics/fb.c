#include <limine.h>
#include <stdint.h>
#include <fb.h>
#include <memory.h>
#include <psf.h>

extern unsigned char *_binary_zap_light16_psf_start;
extern unsigned char *_binary_zap_light16_psf_end;

static volatile struct limine_framebuffer_request fb_request = {
	.id = LIMINE_FRAMEBUFFER_REQUEST,
	.revision = 0
};

uint8_t *framebuffer = 0;
uint16_t framebuffer_width;
uint16_t framebuffer_height;
uint32_t framebuffer_pitch;

struct limine_framebuffer limine_fb;

void init_fb()
{
	struct limine_framebuffer *fb_response = fb_request.response->framebuffers[0];
	
	framebuffer = (uint8_t *)fb_response->address;
	framebuffer_height = fb_response->height;
	framebuffer_width = fb_response->width;
	framebuffer_pitch = fb_response->pitch;
	memcpy(&limine_fb, fb_response, sizeof(struct limine_framebuffer));
}


void draw_pixel(uint32_t x, uint32_t y, uint32_t color)
{
	if (x >= framebuffer_width || y >= framebuffer_height) return;
	
	uint32_t *pixel = (uint32_t *)(framebuffer + y * framebuffer_pitch + x * 4);
	
	*pixel = color;
}

void draw_text(uint32_t x, uint32_t y, const char *text, uint32_t color)
{
	while(*text)
	{
		psf_putc(x, y, *text, color);
		x += 8;
		text++;
	}
}
