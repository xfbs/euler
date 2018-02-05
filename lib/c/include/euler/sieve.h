//! Functions for sieving for prime numbers, see @ref sieve
//! @file sieve.h
//! @todo incorporate into prime.h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#pragma once

//! Functions for sieving for prime numbers.
//!
//! These functions provide an easy interface for sieving for prime numbers.
//!
//! @defgroup sieve sieve
//! @{

//! Sieve strict, used for keeping sieved primes.
typedef struct {
  //! Sieved state
  bool *state;

  //! Sieve of sieve
  size_t len;
} sieve_t;

//! Generate a new sieve.
sieve_t sieve_new(size_t size);

//! Free a sieve instance.
void sieve_free(sieve_t *p);

//! Generate the nth prime.
uint32_t sieve_nth(sieve_t *p, size_t n);

//! For a given prime, check which index it has.
size_t sieve_which(sieve_t *p, uint32_t pr);

//! Check if `num` is prime.
bool sieve_check(sieve_t *p, uint32_t num);

//! Check how many primes there are below `n`.
size_t sieve_below(sieve_t *p, uint32_t n);

//! @}
