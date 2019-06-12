// file: doc_test.c
// autogenerated from documentation in headers
// don't modify this file - it will be overwritten
// this script assumes it's begin ran from within the test/ directory
#include <euler/collatz.h>
#include <euler/common.h>
#include <euler/math.h>
#include <euler/modular_arithmetic.h>
#include <euler/prime.h>
#include <euler/sieve.h>
#include <euler/test.h>
#include <euler/vec.h>
#include <euler/vec16.h>
#include <euler/vec32.h>
#include <euler/vec64.h>
#include <euler/vec8.h>
#include <euler/vecp.h>
#include <stdlib.h>
#include <string.h>

void doctest_math_lcm() {
  assert(lcm(10, 5) == 10);
  assert(lcm(3, 5) == 15);
  assert(lcm(6, 14) == 42);
}

void doctest_math_gcd() {
  assert(gcd(2, 3) == 1);
  assert(gcd(14, 12) == 2);
  assert(gcd(55, 11) == 11);
}

void doctest_math_factorial() {
  assert(factorial(0) == 1);
  assert(factorial(1) == 1);
  assert(factorial(2) == 2);
  assert(factorial(3) == 6);
  assert(factorial(4) == 24);
}

void doctest_math_divisor_sum() {
  assert(divisor_sum(220) == 284);
  assert(divisor_sum(284) == 220);
}

void doctest_math_is_palindrome() {
  assert(is_palindrome(12321) == true);
  assert(is_palindrome(445644) == false);
}

void doctest_math_fibonacci() {
  assert(fibonacci(0) == 1);
  assert(fibonacci(1) == 1);
  assert(fibonacci(2) == 2);
  assert(fibonacci(3) == 3);
  assert(fibonacci(4) == 5);
  assert(fibonacci(5) == 8);
}

void doctest_modular_arithmetic_sum_mod() {
  uint64_t nums[] = {4, 5, 6, 7, 8};
  assert(sum_mod(nums, 5, 11) == 8);
  assert(sum_mod(nums, 5, 39) == 30);
}

void doctest_modular_arithmetic_mult_mod() {
  assert(mult_mod(56, 93, 44) == 16);
  assert(mult_mod(2, 6, 10) == 2);
}

void doctest_modular_arithmetic_shift_mod() {
  assert(shift_mod(55, 4, 99) == 88);
  assert(shift_mod(1424, 12, 13945) == 3694);
}

void doctest_prime_new() {
  // make new primes instance
  prime_t primes = prime_new();

  // generate a prime
  assert(prime_nth(&primes, 3) == 7);

  // free prime instance
  prime_free(&primes);
}

void doctest_prime_free() {
  // new prime instance
  prime_t primes = prime_new();

  // free instance
  prime_free(&primes);
}

void doctest_prime_nth() {
  // new prime generation instance
  prime_t primes = prime_new();

  assert(prime_nth(&primes, 0) == 2);
  assert(prime_nth(&primes, 1) == 3);
  assert(prime_nth(&primes, 2) == 5);
  assert(prime_nth(&primes, 3) == 7);
  assert(prime_nth(&primes, 25) > 100);

  // free instance
  prime_free(&primes);
}

void doctest_prime_which() {
  // new prime generation instance
  prime_t primes = prime_new();

  // test a few primes
  assert(prime_which(&primes, 7) == 3);
  assert(prime_which(&primes, 19) == 7);
  assert(prime_which(&primes, 10) == SIZE_MAX);

  // free instance
  prime_free(&primes);
}

void doctest_prime_check() {
  // new prime generation instance
  prime_t primes = prime_new();

  // test a few primes
  assert(prime_check(&primes, 2) == true);
  assert(prime_check(&primes, 5) == true);
  assert(prime_check(&primes, 8) == false);
  assert(prime_check(&primes, 9) == false);

  // free instance
  prime_free(&primes);
}

void doctest_prime_below() {
  // new prime generation instance
  prime_t primes = prime_new();

  // generate primes up to 100
  assert(prime_below(&primes, 100) == 25);

  // free prime generation instance
  prime_free(&primes);
}

void doctest_vec_free_1() {
  // allocate vector on the stack
  vec8_t vec = vec8_new(0, 0);

  // free vector contents
  vec8_free(&vec);
}

void doctest_vec_free_2() {
  // allocate new vector on the heap
  vec8_t *vec = vec8_alloc(0, 0);

  // free vector contents
  vec_free(vec);

  // free vector itself
  free(vec);
}

void doctest_vec_get_1() {
  // creates a pre-filled vec8
  vec8_t vec = vec8_new(10, 99);

  // gets the first and last element
  assert(vec_get(&vec, 0) == 99);
  assert(vec_get(&vec, 9) == 99);
  vec_free(&vec);
}

void doctest_vec_get_2() {
  // creates a new empty vec8
  vec16_t vec = vec16_new(0, 0);

  // push some data into it
  vec_push(&vec, 15);
  vec_push(&vec, 95);

  // check values
  assert(vec_get(&vec, 0) == 15);
  assert(vec_get(&vec, 1) == 95);
  vec_free(&vec);
}

void doctest_vec_set_1() {
  // creates a pre-filled vec8
  vec8_t vec = vec8_new(10, 99);

  // returns previous element
  assert(vec_set(&vec, 0, 15) == 99);

  // check if set worked
  assert(vec_get(&vec, 0) == 15);
  vec_free(&vec);
}

void doctest_vec_set_2() {
  // creates a new empty vec8
  vec16_t vec = vec16_new(0, 0);

  // push some data into it
  vec_push(&vec, 15);
  vec_push(&vec, 95);

  // set new values
  vec_set(&vec, 0, 100);
  vec_set(&vec, 1, 200);

  // check values
  assert(vec_get(&vec, 0) == 100);
  assert(vec_get(&vec, 1) == 200);
  vec_free(&vec);
}

void doctest_vec_len() {
  // creates a vec8 with length 2
  vec8_t vec = vec8_new(2, 0);

  // creates a vec16 with length 9
  vec16_t other = vec16_new(9, 0);

  // checks lengths
  assert(vec_len(&vec) == 2);
  assert(vec_len(&other) == 9);
  vec_free(&vec);
  vec_free(&other);
}

void doctest_vec_push() {
  // creates a new empty vec8
  vec8_t vec = vec8_new(0, 0);

  // push some values onto the end
  vec_push(&vec, 77);
  vec_push(&vec, 99);

  // make sure the values are there
  assert(vec_len(&vec) == 2);
  assert(vec_get(&vec, 0) == 77);
  assert(vec_get(&vec, 1) == 99);
  vec_free(&vec);
}

void doctest_vec_reserve() {
  // allocates new vec32
  vec32_t vec = vec32_new(0, 0);

  // reserve enough space
  size_t data_size = 1000000;
  vec_reserve(&vec, data_size);

  // add data
  for(size_t cur = 0; cur < data_size; cur++) {
    vec_push(&vec, 9);
  }

  vec_free(&vec);
}

void doctest_vec_clear() {
  // allocate new pre-initialized vecp
  vecp_t vec = vecp_new(15, NULL);

  // forget all elements in vector
  vec_clear(&vec);

  // check
  assert(vec_len(&vec) == 0);
  vec_free(&vec);
}

void doctest_vec_index() {
  // allocates new vec8
  vec8_t vec = vec8_new(0, 0);

  // adds some data to vec
  vec_push(&vec, 16);
  vec_push(&vec, 19);
  vec_push(&vec, 23);

  // find index of some elements in vector
  assert(vec_index(&vec, 16) == 0);
  assert(vec_index(&vec, 19) == 1);
  assert(vec_index(&vec, 23) == 2);
  assert(vec_index(&vec, 20) == SIZE_MAX);
}

void doctest_vec_sum() {
  // allocate new pre-initialized vector
  vec8_t vec = vec8_new(10, 8);

  // add more values to vector
  vec_push(&vec, 77);
  vec_push(&vec, 10);

  // compute sum of elements
  assert(vec_sum(&vec) == 167);
}

void doctest_vec16_new_1() {
  // creates an empty vec16
  vec16_t vec = vec16_new(0, 0);

  vec16_free(&vec);
}

void doctest_vec16_new_2() {
  // creates a pre-filled vec16
  vec16_t vec = vec16_new(10, 99);

  assert(vec16_len(&vec) == 10);
  assert(vec16_get(&vec, 0) == 99);
  assert(vec16_get(&vec, 9) == 99);
  vec16_free(&vec);
}

void doctest_vec16_alloc_1() {
  // creates an empty vec16
  vec16_t *vec = vec16_alloc(0, 0);

  vec16_free(vec);
  free(vec);
}

void doctest_vec16_alloc_2() {
  // creates a pre-filled vec16
  vec16_t *vec = vec16_alloc(10, 99);

  assert(vec16_len(vec) == 10);
  assert(vec16_get(vec, 0) == 99);
  assert(vec16_get(vec, 9) == 99);
  vec16_free(vec);
  free(vec);
}

void doctest_vec16_free_1() {
  // allocate vector on the stack
  vec16_t vec = vec16_new(0, 0);

  // free vector contents
  vec16_free(&vec);
}

void doctest_vec16_free_2() {
  // allocate new vector on the heap
  vec16_t *vec = vec16_alloc(0, 0);

  // free vector contents
  vec16_free(vec);

  // free vector itself
  free(vec);
}

void doctest_vec16_get_1() {
  // creates a pre-filled vec16
  vec16_t vec = vec16_new(10, 99);

  // gets the first and last element
  assert(vec16_get(&vec, 0) == 99);
  assert(vec16_get(&vec, 9) == 99);
  vec16_free(&vec);
}

void doctest_vec16_get_2() {
  // creates a new empty vec16
  vec16_t vec = vec16_new(0, 0);

  // push some data into it
  vec16_push(&vec, 15);
  vec16_push(&vec, 95);

  // check values
  assert(vec16_get(&vec, 0) == 15);
  assert(vec16_get(&vec, 1) == 95);
  vec16_free(&vec);
}

void doctest_vec16_set_1() {
  // creates a pre-filled vec16
  vec16_t vec = vec16_new(10, 99);

  // returns previous element
  assert(vec16_set(&vec, 0, 15) == 99);

  // check if set worked
  assert(vec16_get(&vec, 0) == 15);
  vec16_free(&vec);
}

void doctest_vec16_set_2() {
  // creates a new empty vec16
  vec16_t vec = vec16_new(0, 0);

  // push some data into it
  vec16_push(&vec, 15);
  vec16_push(&vec, 95);

  // set new values
  vec16_set(&vec, 0, 100);
  vec16_set(&vec, 1, 200);

  // check values
  assert(vec16_get(&vec, 0) == 100);
  assert(vec16_get(&vec, 1) == 200);
  vec16_free(&vec);
}

void doctest_vec16_len() {
  // creates a vec with length 2
  vec16_t vec = vec16_new(2, 0);

  // checks length
  assert(vec16_len(&vec) == 2);
  vec16_free(&vec);
}

void doctest_vec16_push() {
  // creates a new empty vector
  vec16_t vec = vec16_new(0, 0);

  // push some values onto the end
  vec16_push(&vec, 77);
  vec16_push(&vec, 99);

  // make sure the values are there
  assert(vec16_len(&vec) == 2);
  assert(vec16_get(&vec, 0) == 77);
  assert(vec16_get(&vec, 1) == 99);
  vec16_free(&vec);
}

void doctest_vec16_reserve() {
  vec16_t vec = vec16_new(0, 0);

  // reserve enough space
  size_t data_size = 1000000;
  vec16_reserve(&vec, data_size);

  // add data
  for(size_t cur = 0; cur < data_size; cur++) {
    vec16_push(&vec, 9);
  }

  vec16_free(&vec);
}

void doctest_vec16_clear() {
  // allocate new pre-initialized vector
  vec16_t vec = vec16_new(15, 9);

  // forget all elements in vector
  vec16_clear(&vec);

  // check
  assert(vec16_len(&vec) == 0);
  vec16_free(&vec);
}

void doctest_vec16_index() {
  // allocates new vector
  vec16_t vec = vec16_new(0, 0);

  // adds some data to vec
  vec16_push(&vec, 16);
  vec16_push(&vec, 19);
  vec16_push(&vec, 23);

  // find index of some elements in vector
  assert(vec16_index(&vec, 16) == 0);
  assert(vec16_index(&vec, 19) == 1);
  assert(vec16_index(&vec, 23) == 2);
  assert(vec16_index(&vec, 20) == SIZE_MAX);
}

void doctest_vec16_bsearch() {
  // new empty vector
  vec16_t vec = vec16_new(0, 0);

  // adds some data to it
  vec16_push(&vec, 9);
  vec16_push(&vec, 5);
  vec16_push(&vec, 14);
  vec16_push(&vec, 1);

  // sort vector
  vec16_sort(&vec, NULL);

  // bsearch only works for sorted vectors, so sort it
  assert(vec16_get(&vec, 0) == 1);
  assert(vec16_get(&vec, 1) == 5);
  assert(vec16_get(&vec, 2) == 9);
  assert(vec16_get(&vec, 3) == 14);

  // find '9'
  uint32_t target = 9;
  assert(vec16_bsearch(&vec, &target, NULL) == 2);

  // find an element that doesn't exist
  target = 0;
  assert(vec16_bsearch(&vec, &target, NULL) == SIZE_MAX);

  // release
  vec16_free(&vec);
}

void doctest_vec16_sort() {
  // new empty vector
  vec16_t vec = vec16_new(0, 0);

  // adds some data to it
  vec16_push(&vec, 9);
  vec16_push(&vec, 5);
  vec16_push(&vec, 14);
  vec16_push(&vec, 1);

  // sort vector
  vec16_sort(&vec, NULL);

  // check that it's sorted
  assert(vec16_get(&vec, 0) == 1);
  assert(vec16_get(&vec, 1) == 5);
  assert(vec16_get(&vec, 2) == 9);
  assert(vec16_get(&vec, 3) == 14);

  // release
  vec16_free(&vec);
}

void doctest_vec16_sum() {
  // allocate new pre-initialized vector
  vec16_t vec = vec16_new(10, 8);

  // add more values to vector
  vec16_push(&vec, 77);
  vec16_push(&vec, 10);

  // compute sum of elements
  assert(vec16_sum(&vec) == 167);
}

void doctest_vec32_new_1() {
  // creates an empty vec32
  vec32_t vec = vec32_new(0, 0);

  vec32_free(&vec);
}

void doctest_vec32_new_2() {
  // creates a pre-filled vec32
  vec32_t vec = vec32_new(10, 99);

  assert(vec32_len(&vec) == 10);
  assert(vec32_get(&vec, 0) == 99);
  assert(vec32_get(&vec, 9) == 99);
  vec32_free(&vec);
}

void doctest_vec32_alloc_1() {
  // creates an empty vec32
  vec32_t *vec = vec32_alloc(0, 0);

  vec32_free(vec);
  free(vec);
}

void doctest_vec32_alloc_2() {
  // creates a pre-filled vec32
  vec32_t *vec = vec32_alloc(10, 99);

  assert(vec32_len(vec) == 10);
  assert(vec32_get(vec, 0) == 99);
  assert(vec32_get(vec, 9) == 99);
  vec32_free(vec);
  free(vec);
}

void doctest_vec32_free_1() {
  // allocate vector on the stack
  vec32_t vec = vec32_new(0, 0);

  // free vector contents
  vec32_free(&vec);
}

void doctest_vec32_free_2() {
  // allocate new vector on the heap
  vec32_t *vec = vec32_alloc(0, 0);

  // free vector contents
  vec32_free(vec);

  // free vector itself
  free(vec);
}

void doctest_vec32_get_1() {
  // creates a pre-filled vec32
  vec32_t vec = vec32_new(10, 99);

  // gets the first and last element
  assert(vec32_get(&vec, 0) == 99);
  assert(vec32_get(&vec, 9) == 99);
  vec32_free(&vec);
}

void doctest_vec32_get_2() {
  // creates a new empty vec32
  vec32_t vec = vec32_new(0, 0);

  // push some data into it
  vec32_push(&vec, 15);
  vec32_push(&vec, 95);

  // check values
  assert(vec32_get(&vec, 0) == 15);
  assert(vec32_get(&vec, 1) == 95);
  vec32_free(&vec);
}

void doctest_vec32_set_1() {
  // creates a pre-filled vec32
  vec32_t vec = vec32_new(10, 99);

  // returns previous element
  assert(vec32_set(&vec, 0, 15) == 99);

  // check if set worked
  assert(vec32_get(&vec, 0) == 15);
  vec32_free(&vec);
}

void doctest_vec32_set_2() {
  // creates a new empty vec32
  vec32_t vec = vec32_new(0, 0);

  // push some data into it
  vec32_push(&vec, 15);
  vec32_push(&vec, 95);

  // set new values
  vec32_set(&vec, 0, 100);
  vec32_set(&vec, 1, 200);

  // check values
  assert(vec32_get(&vec, 0) == 100);
  assert(vec32_get(&vec, 1) == 200);
  vec32_free(&vec);
}

void doctest_vec32_len() {
  // creates a vec with length 2
  vec32_t vec = vec32_new(2, 0);

  // checks length
  assert(vec32_len(&vec) == 2);
  vec32_free(&vec);
}

void doctest_vec32_push() {
  // creates a new empty vector
  vec32_t vec = vec32_new(0, 0);

  // push some values onto the end
  vec32_push(&vec, 77);
  vec32_push(&vec, 99);

  // make sure the values are there
  assert(vec32_len(&vec) == 2);
  assert(vec32_get(&vec, 0) == 77);
  assert(vec32_get(&vec, 1) == 99);
  vec32_free(&vec);
}

void doctest_vec32_reserve() {
  vec32_t vec = vec32_new(0, 0);

  // reserve enough space
  size_t data_size = 1000000;
  vec32_reserve(&vec, data_size);

  // add data
  for(size_t cur = 0; cur < data_size; cur++) {
    vec32_push(&vec, 9);
  }

  vec32_free(&vec);
}

void doctest_vec32_clear() {
  // allocate new pre-initialized vector
  vec32_t vec = vec32_new(15, 9);

  // forget all elements in vector
  vec32_clear(&vec);

  // check
  assert(vec32_len(&vec) == 0);
  vec32_free(&vec);
}

void doctest_vec32_index() {
  // allocates new vector
  vec32_t vec = vec32_new(0, 0);

  // adds some data to vec
  vec32_push(&vec, 16);
  vec32_push(&vec, 19);
  vec32_push(&vec, 23);

  // find index of some elements in vector
  assert(vec32_index(&vec, 16) == 0);
  assert(vec32_index(&vec, 19) == 1);
  assert(vec32_index(&vec, 23) == 2);
  assert(vec32_index(&vec, 20) == SIZE_MAX);
}

void doctest_vec32_bsearch() {
  // new empty vector
  vec32_t vec = vec32_new(0, 0);

  // adds some data to it
  vec32_push(&vec, 9);
  vec32_push(&vec, 5);
  vec32_push(&vec, 14);
  vec32_push(&vec, 1);

  // sort vector
  vec32_sort(&vec, NULL);

  // bsearch only works for sorted vectors, so sort it
  assert(vec32_get(&vec, 0) == 1);
  assert(vec32_get(&vec, 1) == 5);
  assert(vec32_get(&vec, 2) == 9);
  assert(vec32_get(&vec, 3) == 14);

  // find '9'
  uint32_t target = 9;
  assert(vec32_bsearch(&vec, &target, NULL) == 2);

  // find an element that doesn't exist
  target = 0;
  assert(vec32_bsearch(&vec, &target, NULL) == SIZE_MAX);

  // release
  vec32_free(&vec);
}

void doctest_vec32_sort() {
  // new empty vector
  vec32_t vec = vec32_new(0, 0);

  // adds some data to it
  vec32_push(&vec, 9);
  vec32_push(&vec, 5);
  vec32_push(&vec, 14);
  vec32_push(&vec, 1);

  // sort vector
  vec32_sort(&vec, NULL);

  // check that it's sorted
  assert(vec32_get(&vec, 0) == 1);
  assert(vec32_get(&vec, 1) == 5);
  assert(vec32_get(&vec, 2) == 9);
  assert(vec32_get(&vec, 3) == 14);

  // release
  vec32_free(&vec);
}

void doctest_vec32_sum() {
  // allocate new pre-initialized vector
  vec32_t vec = vec32_new(10, 8);

  // add more values to vector
  vec32_push(&vec, 77);
  vec32_push(&vec, 10);

  // compute sum of elements
  assert(vec32_sum(&vec) == 167);
}

void doctest_vec64_new_1() {
  // creates an empty vec64
  vec64_t vec = vec64_new(0, 0);

  vec64_free(&vec);
}

void doctest_vec64_new_2() {
  // creates a pre-filled vec64
  vec64_t vec = vec64_new(10, 99);

  assert(vec64_len(&vec) == 10);
  assert(vec64_get(&vec, 0) == 99);
  assert(vec64_get(&vec, 9) == 99);
  vec64_free(&vec);
}

void doctest_vec64_alloc_1() {
  // creates an empty vec64
  vec64_t *vec = vec64_alloc(0, 0);

  vec64_free(vec);
  free(vec);
}

void doctest_vec64_alloc_2() {
  // creates a pre-filled vec64
  vec64_t *vec = vec64_alloc(10, 99);

  assert(vec64_len(vec) == 10);
  assert(vec64_get(vec, 0) == 99);
  assert(vec64_get(vec, 9) == 99);
  vec64_free(vec);
  free(vec);
}

void doctest_vec64_free_1() {
  // allocate vector on the stack
  vec64_t vec = vec64_new(0, 0);

  // free vector contents
  vec64_free(&vec);
}

void doctest_vec64_free_2() {
  // allocate new vector on the heap
  vec64_t *vec = vec64_alloc(0, 0);

  // free vector contents
  vec64_free(vec);

  // free vector itself
  free(vec);
}

void doctest_vec64_get_1() {
  // creates a pre-filled vec64
  vec64_t vec = vec64_new(10, 99);

  // gets the first and last element
  assert(vec64_get(&vec, 0) == 99);
  assert(vec64_get(&vec, 9) == 99);
  vec64_free(&vec);
}

void doctest_vec64_get_2() {
  // creates a new empty vec64
  vec64_t vec = vec64_new(0, 0);

  // push some data into it
  vec64_push(&vec, 15);
  vec64_push(&vec, 95);

  // check values
  assert(vec64_get(&vec, 0) == 15);
  assert(vec64_get(&vec, 1) == 95);
  vec64_free(&vec);
}

void doctest_vec64_set_1() {
  // creates a pre-filled vec64
  vec64_t vec = vec64_new(10, 99);

  // returns previous element
  assert(vec64_set(&vec, 0, 15) == 99);

  // check if set worked
  assert(vec64_get(&vec, 0) == 15);
  vec64_free(&vec);
}

void doctest_vec64_set_2() {
  // creates a new empty vec64
  vec64_t vec = vec64_new(0, 0);

  // push some data into it
  vec64_push(&vec, 15);
  vec64_push(&vec, 95);

  // set new values
  vec64_set(&vec, 0, 100);
  vec64_set(&vec, 1, 200);

  // check values
  assert(vec64_get(&vec, 0) == 100);
  assert(vec64_get(&vec, 1) == 200);
  vec64_free(&vec);
}

void doctest_vec64_len() {
  // creates a vec with length 2
  vec64_t vec = vec64_new(2, 0);

  // checks length
  assert(vec64_len(&vec) == 2);
  vec64_free(&vec);
}

void doctest_vec64_push() {
  // creates a new empty vector
  vec64_t vec = vec64_new(0, 0);

  // push some values onto the end
  vec64_push(&vec, 77);
  vec64_push(&vec, 99);

  // make sure the values are there
  assert(vec64_len(&vec) == 2);
  assert(vec64_get(&vec, 0) == 77);
  assert(vec64_get(&vec, 1) == 99);
  vec64_free(&vec);
}

void doctest_vec64_reserve() {
  vec64_t vec = vec64_new(0, 0);

  // reserve enough space
  size_t data_size = 1000000;
  vec64_reserve(&vec, data_size);

  // add data
  for(size_t cur = 0; cur < data_size; cur++) {
    vec64_push(&vec, 9);
  }

  vec64_free(&vec);
}

void doctest_vec64_clear() {
  // allocate new pre-initialized vector
  vec64_t vec = vec64_new(15, 9);

  // forget all elements in vector
  vec64_clear(&vec);

  // check
  assert(vec64_len(&vec) == 0);
  vec64_free(&vec);
}

void doctest_vec64_index() {
  // allocates new vector
  vec64_t vec = vec64_new(0, 0);

  // adds some data to vec
  vec64_push(&vec, 16);
  vec64_push(&vec, 19);
  vec64_push(&vec, 23);

  // find index of some elements in vector
  assert(vec64_index(&vec, 16) == 0);
  assert(vec64_index(&vec, 19) == 1);
  assert(vec64_index(&vec, 23) == 2);
  assert(vec64_index(&vec, 20) == SIZE_MAX);
}

void doctest_vec64_bsearch() {
  // new empty vector
  vec64_t vec = vec64_new(0, 0);

  // adds some data to it
  vec64_push(&vec, 9);
  vec64_push(&vec, 5);
  vec64_push(&vec, 14);
  vec64_push(&vec, 1);

  // sort vector
  vec64_sort(&vec, NULL);

  // bsearch only works for sorted vectors, so sort it
  assert(vec64_get(&vec, 0) == 1);
  assert(vec64_get(&vec, 1) == 5);
  assert(vec64_get(&vec, 2) == 9);
  assert(vec64_get(&vec, 3) == 14);

  // find '9'
  uint64_t target = 9;
  assert(vec64_bsearch(&vec, &target, NULL) == 2);

  // find an element that doesn't exist
  target = 0;
  assert(vec64_bsearch(&vec, &target, NULL) == SIZE_MAX);

  // release
  vec64_free(&vec);
}

void doctest_vec64_sort() {
  // new empty vector
  vec64_t vec = vec64_new(0, 0);

  // adds some data to it
  vec64_push(&vec, 9);
  vec64_push(&vec, 5);
  vec64_push(&vec, 14);
  vec64_push(&vec, 1);

  // sort vector
  vec64_sort(&vec, NULL);

  // check that it's sorted
  assert(vec64_get(&vec, 0) == 1);
  assert(vec64_get(&vec, 1) == 5);
  assert(vec64_get(&vec, 2) == 9);
  assert(vec64_get(&vec, 3) == 14);

  // release
  vec64_free(&vec);
}

void doctest_vec64_sum() {
  // allocate new pre-initialized vector
  vec64_t vec = vec64_new(10, 8);

  // add more values to vector
  vec64_push(&vec, 77);
  vec64_push(&vec, 10);

  // compute sum of elements
  assert(vec64_sum(&vec) == 167);
}

void doctest_vec8_new_1() {
  // creates an empty vec8
  vec8_t vec = vec8_new(0, 0);

  vec8_free(&vec);
}

void doctest_vec8_new_2() {
  // creates a pre-filled vec8
  vec8_t vec = vec8_new(10, 99);

  assert(vec8_len(&vec) == 10);
  assert(vec8_get(&vec, 0) == 99);
  assert(vec8_get(&vec, 9) == 99);
  vec8_free(&vec);
}

void doctest_vec8_alloc_1() {
  // creates an empty vec8
  vec8_t *vec = vec8_alloc(0, 0);

  vec8_free(vec);
  free(vec);
}

void doctest_vec8_alloc_2() {
  // creates a pre-filled vec8
  vec8_t *vec = vec8_alloc(10, 99);

  assert(vec8_len(vec) == 10);
  assert(vec8_get(vec, 0) == 99);
  assert(vec8_get(vec, 9) == 99);
  vec8_free(vec);
  free(vec);
}

void doctest_vec8_free_1() {
  // allocate vector on the stack
  vec8_t vec = vec8_new(0, 0);

  // free vector contents
  vec8_free(&vec);
}

void doctest_vec8_free_2() {
  // allocate new vector on the heap
  vec8_t *vec = vec8_alloc(0, 0);

  // free vector contents
  vec8_free(vec);

  // free vector itself
  free(vec);
}

void doctest_vec8_get_1() {
  // creates a pre-filled vec8
  vec8_t vec = vec8_new(10, 99);

  // gets the first and last element
  assert(vec8_get(&vec, 0) == 99);
  assert(vec8_get(&vec, 9) == 99);
  vec8_free(&vec);
}

void doctest_vec8_get_2() {
  // creates a new empty vec8
  vec8_t vec = vec8_new(0, 0);

  // push some data into it
  vec8_push(&vec, 15);
  vec8_push(&vec, 95);

  // check values
  assert(vec8_get(&vec, 0) == 15);
  assert(vec8_get(&vec, 1) == 95);
  vec8_free(&vec);
}

void doctest_vec8_set_1() {
  // creates a pre-filled vec8
  vec8_t vec = vec8_new(10, 99);

  // returns previous element
  assert(vec8_set(&vec, 0, 15) == 99);

  // check if set worked
  assert(vec8_get(&vec, 0) == 15);
  vec8_free(&vec);
}

void doctest_vec8_set_2() {
  // creates a new empty vec8
  vec8_t vec = vec8_new(0, 0);

  // push some data into it
  vec8_push(&vec, 15);
  vec8_push(&vec, 95);

  // set new values
  vec8_set(&vec, 0, 100);
  vec8_set(&vec, 1, 200);

  // check values
  assert(vec8_get(&vec, 0) == 100);
  assert(vec8_get(&vec, 1) == 200);
  vec8_free(&vec);
}

void doctest_vec8_len() {
  // creates a vec with length 2
  vec8_t vec = vec8_new(2, 0);

  // checks length
  assert(vec8_len(&vec) == 2);
  vec8_free(&vec);
}

void doctest_vec8_push() {
  // creates a new empty vector
  vec8_t vec = vec8_new(0, 0);

  // push some values onto the end
  vec8_push(&vec, 77);
  vec8_push(&vec, 99);

  // make sure the values are there
  assert(vec8_len(&vec) == 2);
  assert(vec8_get(&vec, 0) == 77);
  assert(vec8_get(&vec, 1) == 99);
  vec8_free(&vec);
}

void doctest_vec8_reserve() {
  vec8_t vec = vec8_new(0, 0);

  // reserve enough space
  size_t data_size = 1000000;
  vec8_reserve(&vec, data_size);

  // add data
  for(size_t cur = 0; cur < data_size; cur++) {
    vec8_push(&vec, 9);
  }

  vec8_free(&vec);
}

void doctest_vec8_clear() {
  // allocate new pre-initialized vector
  vec8_t vec = vec8_new(15, 9);

  // forget all elements in vector
  vec8_clear(&vec);

  // check
  assert(vec8_len(&vec) == 0);
  vec8_free(&vec);
}

void doctest_vec8_index() {
  // allocates new vector
  vec8_t vec = vec8_new(0, 0);

  // adds some data to vec
  vec8_push(&vec, 16);
  vec8_push(&vec, 19);
  vec8_push(&vec, 23);

  // find index of some elements in vector
  assert(vec8_index(&vec, 16) == 0);
  assert(vec8_index(&vec, 19) == 1);
  assert(vec8_index(&vec, 23) == 2);
  assert(vec8_index(&vec, 20) == SIZE_MAX);
}

void doctest_vec8_bsearch() {
  // new empty vector
  vec8_t vec = vec8_new(0, 0);

  // adds some data to it
  vec8_push(&vec, 9);
  vec8_push(&vec, 5);
  vec8_push(&vec, 14);
  vec8_push(&vec, 1);

  // sort vector
  vec8_sort(&vec, NULL);

  // bsearch only works for sorted vectors, so sort it
  assert(vec8_get(&vec, 0) == 1);
  assert(vec8_get(&vec, 1) == 5);
  assert(vec8_get(&vec, 2) == 9);
  assert(vec8_get(&vec, 3) == 14);

  // find '9'
  uint32_t target = 9;
  assert(vec8_bsearch(&vec, &target, NULL) == 2);

  // find an element that doesn't exist
  target = 0;
  assert(vec8_bsearch(&vec, &target, NULL) == SIZE_MAX);

  // release
  vec8_free(&vec);
}

void doctest_vec8_sort() {
  // new empty vector
  vec8_t vec = vec8_new(0, 0);

  // adds some data to it
  vec8_push(&vec, 9);
  vec8_push(&vec, 5);
  vec8_push(&vec, 14);
  vec8_push(&vec, 1);

  // sort vector
  vec8_sort(&vec, NULL);

  // check that it's sorted
  assert(vec8_get(&vec, 0) == 1);
  assert(vec8_get(&vec, 1) == 5);
  assert(vec8_get(&vec, 2) == 9);
  assert(vec8_get(&vec, 3) == 14);

  // release
  vec8_free(&vec);
}

void doctest_vec8_sum() {
  // allocate new pre-initialized vector
  vec8_t vec = vec8_new(10, 8);

  // add more values to vector
  vec8_push(&vec, 77);
  vec8_push(&vec, 10);

  // compute sum of elements
  assert(vec8_sum(&vec) == 167);
}

void doctest_vecp_new_1() {
  // creates an empty vecp
  vecp_t vec = vecp_new(0, NULL);
  vecp_free(&vec);
}

void doctest_vecp_new_2() {
  // element to point to
  int a;

  // creates a pre-filled vecp
  vecp_t vec = vecp_new(10, &a);

  assert(vecp_len(&vec) == 10);
  assert(vecp_get(&vec, 0) == &a);
  assert(vecp_get(&vec, 9) == &a);
  vecp_free(&vec);
}

void doctest_vecp_alloc_1() {
  // creates an empty vecp
  vecp_t *vec = vecp_alloc(0, NULL);

  vecp_free(vec);
  free(vec);
}

void doctest_vecp_alloc_2() {
  // element to point to
  int a;

  // creates a pre-filled vecp
  vecp_t *vec = vecp_alloc(10, &a);

  assert(vecp_len(vec) == 10);
  assert(vecp_get(vec, 0) == &a);
  assert(vecp_get(vec, 9) == &a);
  vecp_free(vec);
  free(vec);
}

void doctest_vecp_free_1() {
  // allocate vector on the stack
  vecp_t vec = vecp_new(0, NULL);

  // free vector contents
  vecp_free(&vec);
}

void doctest_vecp_free_2() {
  // allocate new vector on the heap
  vecp_t *vec = vecp_alloc(0, NULL);

  // free vector contents
  vecp_free(vec);

  // free vector itself
  free(vec);
}

void doctest_vecp_get_1() {
  // element to point to
  int a;

  // creates a pre-filled vecp
  vecp_t vec = vecp_new(10, &a);

  // gets the first and last element
  assert(vecp_get(&vec, 0) == &a);
  assert(vecp_get(&vec, 9) == &a);
  vecp_free(&vec);
}

void doctest_vecp_get_2() {
  // data to point to
  int a, b;

  // creates a new empty vecp
  vecp_t vec = vecp_new(0, NULL);

  // push some data into it
  vecp_push(&vec, &a);
  vecp_push(&vec, &b);

  // check values
  assert(vecp_get(&vec, 0) == &a);
  assert(vecp_get(&vec, 1) == &b);
  vecp_free(&vec);
}

void doctest_vecp_set_1() {
  // creates a pre-filled vecp
  vecp_t vec = vecp_new(10, NULL);

  // element to point to
  int a;

  // returns previous element
  assert(vecp_set(&vec, 0, &a) == NULL);

  // check if set worked
  assert(vecp_get(&vec, 0) == &a);
  vecp_free(&vec);
}

void doctest_vecp_set_2() {
  // creates a new empty vecp
  vecp_t vec = vecp_new(0, NULL);

  // data to point to
  int a, b;

  // push some data into it
  vecp_push(&vec, NULL);
  vecp_push(&vec, NULL);

  // set new values
  vecp_set(&vec, 0, &a);
  vecp_set(&vec, 1, &b);

  // check values
  assert(vecp_get(&vec, 0) == &a);
  assert(vecp_get(&vec, 1) == &b);
  vecp_free(&vec);
}

void doctest_vecp_len() {
  // creates a vec with length 2
  vecp_t vec = vecp_new(2, NULL);

  // checks length
  assert(vecp_len(&vec) == 2);
  vecp_free(&vec);
}

void doctest_vecp_push() {
  // creates a new empty vector
  vecp_t vec = vecp_new(0, NULL);

  // elements to point at
  int a, b;

  // push some values onto the end
  vecp_push(&vec, &a);
  vecp_push(&vec, &b);

  // make sure the values are there
  assert(vecp_len(&vec) == 2);
  assert(vecp_get(&vec, 0) == &a);
  assert(vecp_get(&vec, 1) == &b);
  vecp_free(&vec);
}

void doctest_vecp_reserve() {
  vecp_t vec = vecp_new(0, NULL);

  // reserve enough space
  size_t data_size = 1000000;
  vecp_reserve(&vec, data_size);

  // add data
  for(size_t cur = 0; cur < data_size; cur++) {
    vecp_push(&vec, NULL);
  }

  vecp_free(&vec);
}

void doctest_vecp_clear() {
  // allocate new pre-initialized vector
  vecp_t vec = vecp_new(15, NULL);

  // forget all elements in vector
  vecp_clear(&vec);

  // check
  assert(vecp_len(&vec) == 0);
  vecp_free(&vec);
}

void doctest_vecp_index() {
  // allocates new vector
  vecp_t vec = vecp_new(0, NULL);

  // data to point to
  int a, b, c, d;

  // adds some data to vec
  vecp_push(&vec, &a);
  vecp_push(&vec, &b);
  vecp_push(&vec, &c);

  // find index of some elements in vector
  assert(vecp_index(&vec, &a) == 0);
  assert(vecp_index(&vec, &b) == 1);
  assert(vecp_index(&vec, &c) == 2);
  assert(vecp_index(&vec, &d) == SIZE_MAX);
}

void doctest_vecp_lsearch() {
  // new pointer vector
  vecp_t vec = vecp_new(0, NULL);

  // some strings
  vecp_push(&vec, "Hello");
  vecp_push(&vec, "vecp_test");
  vecp_push(&vec, "World");
  vecp_push(&vec, "12345qwerty");
  vecp_push(&vec, "World");

  // find the strings. note that lsearch always returns the first match.
  assert(vecp_lsearch(&vec, "Hello", (vecp_cmp) strcmp) == 0);
  assert(vecp_lsearch(&vec, "World", (vecp_cmp) strcmp) == 2);

  vecp_free(&vec);
}

void doctest_vecp_bsearch_1() {
  // new empty vector
  vecp_t vec = vecp_new(0, NULL);

  // targets
  void *a = (void *) 0xABCDEF1;
  void *b = (void *) 0xABCDEF2;
  void *c = (void *) 0xABCDEF3;
  void *d = (void *) 0xABCDEF4;

  // adds some data to it
  vecp_push(&vec, a);
  vecp_push(&vec, b);
  vecp_push(&vec, c);
  vecp_push(&vec, d);

  // sort vector
  //vecp_sort(&vec, NULL);

  // check that all pointers exist
  assert(vecp_bsearch(&vec, a, NULL) != SIZE_MAX);
  assert(vecp_bsearch(&vec, b, NULL) != SIZE_MAX);
  assert(vecp_bsearch(&vec, c, NULL) != SIZE_MAX);
  assert(vecp_bsearch(&vec, d, NULL) != SIZE_MAX);
  assert(vecp_bsearch(&vec, (void *) 0x2AAA899, NULL) == SIZE_MAX);

  // check if the get the correct element back
  assert(vecp_get(&vec, vecp_bsearch(&vec, a, NULL)) == a);
  assert(vecp_get(&vec, vecp_bsearch(&vec, b, NULL)) == b);
  assert(vecp_get(&vec, vecp_bsearch(&vec, c, NULL)) == c);
  assert(vecp_get(&vec, vecp_bsearch(&vec, d, NULL)) == d);

  // release
  vecp_free(&vec);
}

void doctest_vecp_bsearch_2() {
  // new emprt vector
  vecp_t vec = vecp_new(0, NULL);

  // add strings (pre-sorted)
  vecp_push(&vec, "another");
  vecp_push(&vec, "birthday");
  vecp_push(&vec, "comes");
  vecp_push(&vec, "deliberately");

  // find the indexes of the words
  assert(vecp_bsearch(&vec, "another", (vecp_cmp) strcmp) == 0);
  assert(vecp_bsearch(&vec, "birthday", (vecp_cmp) strcmp) == 1);
  assert(vecp_bsearch(&vec, "comes", (vecp_cmp) strcmp) == 2);
  assert(vecp_bsearch(&vec, "deliberately", (vecp_cmp) strcmp) == 3);
  assert(vecp_bsearch(&vec, "easy", (vecp_cmp) strcmp) == SIZE_MAX);

  // release
  vecp_free(&vec);
}

void doctest_vecp_sort_1() {
  // new empty vector
  vecp_t vec = vecp_new(0, NULL);

  // adds some data to it
  vecp_push(&vec, (void *) 0xDEADBEEF);
  vecp_push(&vec, (void *) 0xCAEFBABE);
  vecp_push(&vec, (void *) 0xC0FFEBAD);
  vecp_push(&vec, (void *) 0xAABBCCDD);

  // sort vector: after this, vec contains sorted pointers to a, b, d and d.
  vecp_sort(&vec, NULL);

  // check order of pointers
  assert(vecp_get(&vec, 0) == (void *) 0xAABBCCDD);
  assert(vecp_get(&vec, 1) == (void *) 0xC0FFEBAD);
  assert(vecp_get(&vec, 2) == (void *) 0xCAEFBABE);
  assert(vecp_get(&vec, 3) == (void *) 0xDEADBEEF);

  // release
  vecp_free(&vec);
}

void doctest_vecp_sort_2() {
  // new empty vector
  vecp_t vec = vecp_new(0, NULL);

  // add some strings to vector
  vecp_push(&vec, "Hello");
  vecp_push(&vec, "Testing");
  vecp_push(&vec, "Andersson");

  // sort strings in vector with strcmp
  vecp_sort(&vec, (vecp_cmp) strcmp);

  assert(0 == strcmp(vecp_get(&vec, 0), "Andersson"));
  assert(0 == strcmp(vecp_get(&vec, 1), "Hello"));
  assert(0 == strcmp(vecp_get(&vec, 2), "Testing"));

  // release
  vecp_free(&vec);
}
