#include <stdint.h>
#include <stddef.h>
#include <simple_prime.h>
#include <bitvec.h>
#pragma once

uint32_t solve(size_t max);
size_t primes_below(prime_t *p, uint32_t n);
void check_prime_cycle(prime_t *p, bitvec_t *b, size_t cur);
