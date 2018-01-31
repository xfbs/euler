//! @file prime.h
//! @author Patrick M. Elsen
//! @date 2018
//! @copyright MIT license
//! @brief functions for generating prime numbers.
//! @default these functions provide an easy interface for generating sequential
//! prime numbers.
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#pragma once

//! @defgroup prime prime
//! @brief functions for generating prime numbers.
//! @{

//! primes struct, used for caching generated primes.
//! @todo change to use vec32 internally
typedef struct {
  uint32_t *primes;
  size_t len;
  size_t cap;
} prime_t;

//! make new prime generation instance.
//!
//! generates new instance of the `prime_t` struct, which is used for caching
//! generated primes and needs to be passed to all prime functions.
//!
//! @return a `prime_t` instance.
//!
//! ## Examples
//!
//! ```c
//! // make new primes instance
//! prime_t primes = prime_new();
//!
//! // generate a prime
//! assert(prime_nth(&primes, 3) == 7);
//!
//! // free prime instance
//! prime_free(&primes);
//! ```
prime_t prime_new();

void prime_free(prime_t *p);
uint32_t prime_nth(prime_t *p, size_t n);
size_t prime_which(prime_t *p, uint32_t pr);
bool prime_check(prime_t *p, uint32_t num);
size_t prime_below(prime_t *p, uint32_t n);

//! @}
