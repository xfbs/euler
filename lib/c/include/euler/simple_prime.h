#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#pragma once

typedef struct {
    uint32_t *primes;
    size_t len;
    size_t cap;
} prime_t;

prime_t prime_new();
void prime_free(prime_t *p);
uint32_t prime_nth(prime_t *p, size_t n);
size_t prime_which(prime_t *p, uint32_t pr);
bool prime_check(prime_t *p, uint32_t num);
size_t primes_below(prime_t *p, uint32_t n);
