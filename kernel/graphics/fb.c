#include <limine.h>
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
	
	framebuffer.red_shift = fb_response->red_mask_shift;
	framebuffer.red_size = fb_response->red_mask_size;
	
	framebuffer.green_shift = fb_response->green_mask_shift;
	framebuffer.green_size = fb_response->green_mask_size;
	
	framebuffer.blue_shift = fb_response->blue_mask_shift;
	framebuffer.blue_size = fb_response->blue_mask_size;
	
	memcpy(&limine_fb, fb_response, sizeof(struct limine_framebuffer));
}