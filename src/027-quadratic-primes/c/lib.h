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

int32_t solve(int32_t max);

prime_t prime_new();
uint32_t prime_next(prime_t *p);
uint32_t prime_prev(prime_t *p);
void prime_reset(prime_t *p);

uint32_t quadratic_prime_run(prime_t *p, int32_t a, int32_t b);
