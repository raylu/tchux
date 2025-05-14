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
uint16_t framebufferWidth;
uint16_t framebufferHeight;
uint32_t framebufferPitch;

struct limine_framebuffer limine_fb;

void init_fb()
{
	struct limine_framebuffer *fb_response = fb_request.response->framebuffers[0];
	
	framebuffer = (uint8_t *)fb_response->address;
	framebufferHeight = fb_response->height;
	framebufferWidth = fb_response->width;
	framebufferPitch = fb_response->pitch;
	memcpy(&limine_fb, fb_response, sizeof(struct limine_framebuffer));
}


void draw_pixel(uint32_t x, uint32_t y, uint32_t color)
{
	if (x >= framebufferWidth || y >= framebufferHeight) return;
	
	uint32_t *pixel = (uint32_t *)(framebuffer + y * framebufferPitch + x * 4);
	
	*pixel = color;
}

/*
void draw_char(uint32_t x, uint32_t y, char c, uint32_t color)
{	
	struct psf1_header *header = (struct psf1_header *)&_binary_zap_light16_psf_start;
	
	if (header->magic != 0x0436) return;
	
	uint8_t *glyphs = (uint8_t *)&_binary_zap_light16_psf_start + sizeof(struct psf1_header);
	uint8_t *glyph = glyphs + (c * header->charsize);
	
	for (uint32_t i = 0; i < header->charsize; i++)
	{
		for (uint32_t j = 0; j < 8; j++)
		{
			if (glyph[i] & (1 << (7 - j)))
			{
				draw_pixel(x + j, y + i, color);
			}
		}
	}
}

void draw_text(uint32_t x, uint32_t y, const char *text, uint32_t color)
{
	while(*text)
	{
		draw_char(x, y, *text, color);
		x += 8;
		text++;
	}
}
*/