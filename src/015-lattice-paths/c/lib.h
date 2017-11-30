#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma once

typedef struct {
    uint64_t **cache;
    size_t x;
    size_t y;
} cache_t;

uint64_t solve(size_t x, size_t y);
uint64_t paths(cache_t cache, size_t x, size_t y);
