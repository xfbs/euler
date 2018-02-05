//! @file test.h
//! @author Patrick Elsen
//! @brief tiny C unit testing helpers
#include <assert.h>
#include <stdio.h>
#include <string.h>

//! @defgroup test test
//! @brief tiny C unit testing helpers
//! @{

//! define the main testing function.
//!
//! this function may only be called once, and with it you define a function
//! that will run all the tests that you specify.
//!
//! inside the function, call RUN() to run the tests you want to run.
//!
//! ## Examples
//!
//! ```c
//! void test_something() {
//!   assert(5 == 5);
//!   assert(25 == (5 * 5));
//! }
//!
//! TESTS() {
//!   RUN(test_something);
//! }
//! ```
#define TESTS()                                                                \
  const char *_get_file_name() { return __FILE__; }                            \
  void _tests()

//! run a single test function with the provided name
//!
//! this function will run the given function and prime some helpful messages to
//! stdout.
//!
//! this function is meant to be called in a TESTS() block.
//!
//! @param t function to test, must be a `void` function.
//!
//! ## Examples
//!
//! ```c
//! void test_something() {
//!   assert(true);
//! }
//!
//! TESTS() {
//!   RUN(test_something);
//! }
//! ```
#define RUN(t)                                                                 \
  printf("  - %s: ", #t);                                                      \
  t();                                                                         \
  printf("success.\n")

//! Checks if two strings are equal.
//!
//! @param lhr
//! @param rhs
//! @todo make generic so it also works for other data types
#define assert_eq(lhs, rhs) assert(lhs && rhs && 0 == strcmp(lhs, rhs))

void _tests();
const char *_get_file_name();

#ifdef EULER_TEST_MAIN
int main(int argc, char *argv[]) {
  printf("Running %s...\n", _get_file_name());
  _tests();
  return 0;
}
#endif

//! @}
