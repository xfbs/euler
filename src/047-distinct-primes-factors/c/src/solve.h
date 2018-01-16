#include <euler/simple_prime.h>
#include <stdbool.h>
#include <stdint.h>
#pragma once

// finds the first number of the first `cnt` consecutive integers to have `cnt`
// distinct prime factors each.
uint64_t solve(uint8_t cnt);

// for a given number `num`, populates the array `f` with it's `cnt` prime
// factors using the prime generator `p`, returning true if successful or false
// when there are less or more than `cnt` prime factors.
bool prime_factors(prime_t *p, uint64_t num, uint8_t cnt, uint16_t f[cnt]);

// check if the given `cnt` prime factors of the `cnt` numbers are all distinct
bool distinct_prime_factors(uint8_t cnt, uint16_t fs[cnt][cnt]);
