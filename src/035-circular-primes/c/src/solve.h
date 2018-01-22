#include <stdint.h>
#include <stddef.h>
#include <euler/prime.h>
#include <euler/bitvec.h>
#pragma once

uint32_t solve(size_t max);
void check_prime_cycle(prime_t *p, bitvec_t *b, size_t cur);
