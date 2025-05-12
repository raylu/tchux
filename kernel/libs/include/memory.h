#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

void *memset(void *s, int c, size64_t n);
void *memcpy(void *restrict dest, const void *restrict src, size64_t n);

#endif