#include <cstdint>
#include <euler/prime.hpp>
#pragma once

// for a prime and the digit to substitute, find out in which family the prime
// is.
uint8_t family_size(euler::Prime &primes, uint64_t prime, uint64_t digit);

// checks if a prime number belongs to the given family.
bool check_family(euler::Prime &primes, uint64_t prime, uint8_t family);

// finds the smallest prime that belongs to the given family.
uint64_t solve(uint8_t family);
