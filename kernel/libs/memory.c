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