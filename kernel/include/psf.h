#ifndef PSF_H
#define PSF_H

#include <stdint.h>
#include <stdbool.h>

#define PSF1_FONT_MAGIC 0x0436

struct psf1_header_struct {
    uint16_t magic;
    uint8_t mode;
    uint8_t charsize;
};

struct psf_font_struct
{
	uint32_t magic;
	uint32_t version;
	uint32_t headersize;
    uint32_t flags;
    uint32_t numglyph;
    uint32_t bytesperglyph;
    uint32_t height;
    uint32_t width;
};

extern struct psf1_header_struct *psf;

void load_psf(void *buffer);
void load_default_font();
void psf_putc(uint32_t x, uint32_t y, char c, uint32_t color);

#endif