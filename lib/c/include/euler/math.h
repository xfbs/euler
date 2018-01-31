//! @file math.h
//! @author Patrick M. Elsen
//! @date 2018
//! @copyright MIT license
//! @brief assorted math functions not part of that standard library.
#include <stdint.h>
#pragma once

//! @defgroup math
//! @brief assorted math functions not part of the standard library
//! @{

//! least common multiple of two numbers.
//!
//! compute the least common multiple of two numbers, which is the smallest
//! number that is divisible by both numbers.
//!
//! @param a a number
//! @param b a number
//! @return the least common multiple of `a` and `b`.
//!
//! ## Examples
//!
//! ```c
//! assert(lcm(10, 5) == 10);
//! assert(lcm(3, 5) == 15);
//! assert(lcm(6, 14) == 42);
//! ```
uint64_t lcm(uint64_t a, uint64_t b);

//! greatest common divisor of two numbers.
//!
//! compute the greatest common divisor using euclid's algorithm, which is the
//! largest number that is a divisor of both numbers.
//!
//! @param a a number
//! @param b a number
//! @return greatest common divisor of `a` and `b`
//!
//! ## Examples
//!
//! ```c
//! assert(gcd(2, 3) == 1);
//! assert(gcd(14, 12) == 2);
//! assert(gcd(55, 11) == 11);
//! ```
uint64_t gcd(uint64_t a, uint64_t b);

//! nth factorial number
//!
//! @param nth which factorial to compute
//! @return factorial of nth
//! @warning
//! since factorials grow extremely fast, any `nth` larger than 20 leads to an
//! overflow.
//!
//! ## Examples
//!
//! ```c
//! assert(factorial(0) == 1);
//! assert(factorial(1) == 1);
//! assert(factorial(2) == 2);
//! assert(factorial(3) == 6);
//! assert(factorial(4) == 24);
//! ```
uint64_t factorial(uint8_t nth);

uint32_t divisor_sum(uint32_t num);

static const double PHI = 1.61803398875;
#define PHI3 (PHI * PHI * PHI)

uint64_t next_even_fibonacci(uint64_t fibo);

//! @}
