#include <stdint.h>
#include <stddef.h>
#include <psf.h>

extern char _binary_zap_light16_psf_start;
extern char _binary_zap_light16_psf_end;

uint16_t *unicode;

struct psf_header_struct psf_header;
struct psf_font_struct psf_font;

void psf_init()
{
	uint16_t glyph = 0;
	
	psf_font *font = (psf_font*)&_binary_zap_light16_psf_start;
	
	if (font->flags == 0)
	{
		unicode = NULL;
		return;
	}
	
	char *s = (char *)((unsigned char *)&_binary_zap_light16_psf_start + font->headersize + font->numglyph * font->bytesperglyph);
}