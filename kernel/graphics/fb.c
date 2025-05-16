#include <limine.h>
#include <stdint.h>
#include <fb.h>
#include <memory.h>

static volatile struct limine_framebuffer_request fb_request = {
	.id = LIMINE_FRAMEBUFFER_REQUEST,
	.revision = 0
};

struct limine_framebuffer limine_fb;
struct framebuffer_struct framebuffer;

void init_fb()
{	
	struct limine_framebuffer *fb_response = fb_request.response->framebuffers[0];
	
	framebuffer.addr = fb_response->address;
	framebuffer.height = fb_response->height;
	framebuffer.width = fb_response->width;
	framebuffer.pitch = fb_response->pitch;
	framebuffer.bpp = fb_response->bpp;
	
	memcpy(&limine_fb, fb_response, sizeof(struct limine_framebuffer));
}
