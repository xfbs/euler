#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma once

typedef struct {
    uint32_t *primes;
    size_t len;
    size_t cap;
    size_t cur;
} prime_t;

uint32_t solve(size_t max);
prime_t prime_new();
uint32_t prime_next(prime_t *p);
void prime_reset(prime_t *p);
uint32_t factor_count(prime_t *p, uint32_t);

