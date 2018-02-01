//! @file modular_arithmetic.h
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#pragma once

//! @defgroup mod mod
//! @brief modular arithmetic functions
//! @{

//! computes `pow(num, ext) % mod`
//!
//! @param num base
//! @param exp exponent
//! @param mod modulus
//! @return `num` to the power of `exp` modulus `mod`
//! @todo example
uint64_t pow_mod(uint64_t num, uint64_t exp, uint64_t mod);

//! computers `(num[0] + num[1] ... + num[len-1]) % mod`
//!
//! sums up an array modulus `mod`
//!
//! @param num an array of numbers
//! @param len the length of the array
//! @param mod modulus
//! @return the sum of all numbers in the array modulus `mod`
//!
//! ## Examples
//!
//! ```c
//! uint64_t nums[] = {4, 5, 6, 7, 8};
//! assert(sum_mod(nums, 5, 11) == 8);
//! assert(sum_mod(nums, 5, 39) == 30);
//! ```
uint64_t sum_mod(uint64_t num[], size_t len, uint64_t mod);

//! computes `(a * b) % mod`
//!
//! @param a a factor
//! @param b a factor
//! @param mod modulus
//! @return the product of `a` and `b` modulus `mod`
//!
//! ## Examples
//!
//! ```c
//! assert(mult_mod(56, 93, 44) == 16);
//! assert(mult_mod(2, 6, 10) == 2);
//! ```
uint64_t mult_mod(uint64_t a, uint64_t b, uint64_t mod);

//! computes `(num << amount) % mod`
//!
//! left shifts a number by a specified amount.
//!
//! @param num the number to left-shift
//! @param amount the amount of bits to left-shift the number by
//! @param mod the modulus
//! @return `num` left-shifted by `amount`, modulus `mod`
//!
//! ## Examples
//!
//! ```c
//! assert(shift_mod(55, 4, 99) == 88);
//! assert(shift_mod(1424, 12, 13945) == 3694);
//! ```
uint64_t shift_mod(uint64_t num, uint8_t amount, uint64_t mod);

//! @}
