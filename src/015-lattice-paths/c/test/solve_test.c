#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve_easy() {
  assert(solve(0, 0) == 1);

  assert(solve(0, 0) == 1);
  assert(solve(0, 1) == 1);
  assert(solve(0, 4) == 1);
  assert(solve(0, 9) == 1);

  assert(solve(0, 0) == 1);
  assert(solve(1, 0) == 1);
  assert(solve(3, 0) == 1);
  assert(solve(8, 0) == 1);

  assert(solve(1, 1) == 2);
  assert(solve(1, 3) == 4);
  assert(solve(1, 4) == 5);
  assert(solve(1, 9) == 10);

  assert(solve(1, 1) == 2);
  assert(solve(3, 1) == 4);
  assert(solve(6, 1) == 7);
  assert(solve(8, 1) == 9);
}

void test_solve_harder() {
  assert(solve(2, 2) == 6);
  assert(solve(2, 3) == 10);
  assert(solve(3, 2) == 10);
  assert(solve(5, 3) == 56);
  assert(solve(4, 4) == 70);
  assert(solve(3, 4) == 35);
}

void test_solve_big() {
  assert(solve(4, 6) == 210);
  assert(solve(5, 5) == 252);
  assert(solve(8, 4) == 495);
  assert(solve(5, 7) == 792);

  // this broke the solution before because I used uint32_t which is not
  // large enough, which resulted in an overflow.
  assert(solve(20, 16) == 7307872110);
}

TESTS() {
  RUN(test_solve_easy);
  RUN(test_solve_harder);
  RUN(test_solve_big);
}
