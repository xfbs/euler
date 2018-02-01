//! @file math.h
//! @author Patrick M. Elsen
//! @date 2018
//! @copyright MIT license
//! @brief assorted math functions not part of that standard library.
#include <stdint.h>
#include <stdbool.h>
#pragma once

//! @defgroup math math
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

//! sum of the divisors of num
//!
//! calculates the sum of proper divisors of num, meaning all divisors lower
//! than num itself.
//!
//! @param num a number
//! @return sum of all divisors of `num` that are not equal to `num`.
//!
//! ## Examples
//!
//! ```c
//! assert(divisor_sum(220) == 284);
//! assert(divisor_sum(284) == 220);
//! ```
uint32_t divisor_sum(uint32_t num);

//! checks if the given number is a palindrome.
//!
//! @param num the number to check
//! @return `true` if the number is a palindrome, `false` otherwise.
//!
//! ## Examples
//!
//! ```c
//! assert(is_palindrome(12321) == true);
//! assert(is_palindrome(445644) == false);
//! ```
bool is_palindrome(uint64_t num);

//! return the `nth` pandigital of length `n`
//!
//! a pandigital is a number making use of all numbers from 0 to `n` exactly
//! once, therefore it is a permutation of the set [0..n].
//!
//! @param n how long the pandigital should be
//! @param nth which permutation to return
//! @todo examples
uint32_t nth_pandigital(uint8_t n, uint32_t nth);

//! computes the `nth` fibonacci
//!
//! Fibonacci numbers are a sequence that starts with 1, 1 and each successive
//! number is the sum of the previous two numbers. Since computing it like that
//! is very expensive, this function computes the `nth` fibonacci number in an
//! efficient manner using `PHI` and `ROOT5`.
//!
//! ```c
//! assert(fibonacci(0) == 1);
//! assert(fibonacci(1) == 1);
//! assert(fibonacci(2) == 2);
//! assert(fibonacci(3) == 3);
//! assert(fibonacci(4) == 5);
//! assert(fibonacci(5) == 8);
//! ```
uint64_t fibonacci(uint64_t nth);

//! @}
