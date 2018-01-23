#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#pragma once

typedef struct {
    bool *state;
    size_t len;
} sieve_t;

sieve_t sieve_new(size_t size);
void sieve_free(sieve_t *p);
uint32_t sieve_nth(sieve_t *p, size_t n);
size_t sieve_which(sieve_t *p, uint32_t pr);
bool sieve_check(sieve_t *p, uint32_t num);
size_t sieve_below(sieve_t *p, uint32_t n);
