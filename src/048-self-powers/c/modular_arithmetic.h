#include <strings.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#pragma once

// computes pow(num, ext) % mod
uint64_t pow_mod(uint64_t num, uint64_t exp, uint64_t mod);

// computers (num[0] + num[1] ... + num[len-1]) % mod
uint64_t sum_mod(uint64_t num[], size_t len, uint64_t mod);

// computes (a * b) % mod
uint64_t mult_mod(uint64_t a, uint64_t b, uint64_t mod);

// computes (num << amount) % mod
uint64_t shift_mod(uint64_t num, uint8_t amount, uint64_t mod);
