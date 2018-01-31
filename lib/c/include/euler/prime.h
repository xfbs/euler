//! @file prime.h
//! @author Patrick M. Elsen
//! @date 2018
//! @copyright MIT license
//! @brief functions for generating prime numbers.
//! @detail these functions provide an easy interface for generating sequential
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

//! free the contents of the `prime_t`.
//!
//!
//! @param p the primes struct to free
//! @warning
//! this method only frees the contents of the `prime_t`, not the `prime_t`
//! itself. if it was allocated on the heap, it must be `free()`d also.
//!
//! ## Examples
//!
//! ```c
//! // new prime instance
//! prime_t primes = prime_new();
//!
//! // free instance
//! prime_free(&primes);
//! ```
void prime_free(prime_t *p);

//! generate the nth prime.
//!
//! this method generates all primes up to the `n`th, and then returns the
//! `n`th. counting starts at 0, so the 0th prime is 2. all primes (also
//! intermediate primes) are cached for future lookup.
//!
//! @param p the prime generation instance to use
//! @param n which prime to generate
//! @return the `n`th prime
//!
//! ## Examples
//!
//! ```c
//! // new prime generation instance
//! prime_t primes = prime_new();
//!
//! assert(prime_nth(&primes, 0) == 2);
//! assert(prime_nth(&primes, 1) == 3);
//! assert(prime_nth(&primes, 2) == 5);
//! assert(prime_nth(&primes, 3) == 7);
//! assert(prime_nth(&primes, 25) > 100);
//!
//! // free instance
//! prime_free(&primes);
//! ```
uint32_t prime_nth(prime_t *p, size_t n);

//! reverse lookup for primes.
//!
//! given a prime `pr`, find which prime it is.
//!
//! @param p prime generation instance to use
//! @param pr prime to look up
//! @return position of prime or `SIZE_MAX`
//!
//! ## Examples
//!
//! ```c
//! // new prime generation instance
//! prime_t primes = prime_new();
//!
//! // test a few primes
//! assert(prime_which(&primes, 7) == 3);
//! assert(prime_which(&primes, 19) == 7);
//! assert(prime_which(&primes, 10) == SIZE_MAX);
//!
//! // free instance
//! prime_free(&primes);
//! ```
size_t prime_which(prime_t *p, uint32_t pr);

//! check if a number is prime
//!
//! checks if the number is prime by testing it for divisibily by all primes up
//! to `sqrt(num)`.
//!
//! @param p prime generation instance to use
//! @param num number to check
//! @return `true` if the number is prime, `false` otherwise
//!
//! ## Examples
//!
//! ```c
//! // new prime generation instance
//! prime_t primes = prime_new();
//!
//! // test a few primes
//! assert(prime_check(&primes, 2) == true);
//! assert(prime_check(&primes, 5) == true);
//! assert(prime_check(&primes, 8) == false);
//! assert(prime_check(&primes, 9) == false);
//!
//! // free instance
//! prime_free(&primes);
//! ```
bool prime_check(prime_t *p, uint32_t num);

//! generates all primes below `n` and returns how many there are.
//!
//! @param p prime generation instance to use
//! @param n maximum of when to generate primes
//!
//! ## Examples
//!
//! ```c
//! // new prime generation instance
//! prime_t primes = prime_new();
//!
//! // generate primes up to 100
//! assert(prime_below(&primes, 100) == 25);
//!
//! // free prime generation instance
//! prime_free(&primes);
//! ```
size_t prime_below(prime_t *p, uint32_t n);

//! @}
