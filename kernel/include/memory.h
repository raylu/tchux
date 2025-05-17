#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

void *memset(void *s, int c, size_t n);
void *memcpy(void *restrict dest, void *restrict src, size_t n);

#endif