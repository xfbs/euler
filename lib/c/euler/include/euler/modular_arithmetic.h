//! Modular arithmetic functions, see @ref modarith.
//! @file modular_arithmetic.h
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#pragma once

//! Modular arithmetic functions.
//! A group of functions that can be used to perform modular arithmetic.
//! @defgroup modarith modarith
//! @{

//! Computes `pow(num, ext) % mod`
//!
//! @param num Base
//! @param exp Exponent
//! @param mod Modulus
//! @return `num` to the power of `exp` modulus `mod`
//!
//! ## Examples
//!
//! ```c
//! assert(pow_mod(15, 456, 11327) == 2170);
//! assert(pow_mod(19, 102, 19921) == 11790);
//! ```
uint64_t pow_mod(uint64_t num, uint64_t exp, uint64_t mod);

//! Computers the sum of all integers in `num` modulus `mod`
//!
//! @param num An array of numbers
//! @param len Length of the array
//! @param mod Modulus
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
//! @param a Factor
//! @param b Factor
//! @param mod Modulus
//! @return Product of `a` and `b` modulus `mod`
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
