#include <memory.h>
#include <stdint.h>

void *memset(void *s, int c, size_t n)
{
	uint8_t *p = (uint8_t *)s;
	
	for (size_t i = 0; i < n; i++)
	{
		p[i] = (uint8_t)c;
	}
	
	return s;
}

void *memcpy(void *restrict dest, void *restrict src, size_t n)
{
	uint8_t *restrict pdest = (uint8_t *restrict)dest;
	const uint8_t *restrict psrc = (const uint8_t *restrict)src;
	
	for (size_t i = 0; i < n; i++)
	{
		pdest[i] = psrc[i];
	}
	
	return dest;
}