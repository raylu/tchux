#include <memory.h>
#include <stdint.h>

void *memset(void *s, int c, size64_t n)
{
	uint8_t *p = (uint8_t *)s;
	
	for (size64_t i = 0; i < n; i++)
	{
		p[i] = (uint8_t)c;
	}
	
	return s;
}

void *memcpy(void *restrict dest, const void *restrict src, size64_t n)
{
	uint8_t *restrict pdest = (uint8_t *restrict)dest;
	const uint8_t *restrict psrc = (const uint8_t *restrict)src;
	
	for (size64_t i = 0; i < n; i++)
	{
		pdest[i] = psrc[i];
	}
	
	return dest;
}