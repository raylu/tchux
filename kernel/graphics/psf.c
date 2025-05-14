#include <psf.h>
#include <stdint.h>
#include <stdbool.h>
#include <fb.h>

#include <gohufont.h>

extern char _binary_zap_light16_psf_start;
extern char _binary_zap_light16_psf_end;

struct psf1_header_struct psf1_header;
struct psf_font_struct psf_font;
struct psf1_header_struct *psf;

void load_psf(void *buffer)
{
	psf1_header = *(struct psf1_header_struct *)buffer;
	psf = (struct psf1_header_struct *)buffer;
	
	psf_font.magic = psf1_header.magic;
	psf_font.version = 1;
	psf_font.headersize = sizeof(struct psf1_header_struct);
	psf_font.flags = (psf1_header.mode == 1) ? 1 : 0;
	psf_font.numglyph = (psf1_header.mode & 0x01) ? 512 : 256;
	psf_font.bytesperglyph = psf1_header.charsize;
	psf_font.height = psf1_header.charsize;
	psf_font.width = 8;
}

void load_default_font()
{
	load_psf(&psf_gohufont[0]);
}

void psf_putc(uint32_t x, uint32_t y, char c, uint32_t color)
{
	uint8_t *targ = (uint8_t*)((size64_t)psf + sizeof(struct psf1_header_struct) + c * psf->charsize);
	
	for (uint32_t i = 0; i < psf->charsize; i++)
	{
		for (uint32_t j = 0; j < 8; j++)
		{
			if (targ[i] & (1 << (8 - j)))
			{
				draw_pixel(x + j, y + i, color);
			}
		}
	}
	
}