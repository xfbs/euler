#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma once

typedef struct {
    uint32_t *table;
    uint32_t limit;
} collatz_cache_t;

uint32_t solve(uint32_t limit);
collatz_cache_t collatz_cache(uint32_t limit);
uint32_t collatz_length(uint32_t number, collatz_cache_t cache);
uint32_t collatz_longest(collatz_cache_t cache);
