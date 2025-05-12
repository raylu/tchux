#include <limine.h>
#include <stdint.h>
#include <fb.h>
#include <memory.h>

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