
#include "solve.h"
#include <euler/test.h>

void test_solve_easy() {
  assert(solve_015(0, 0) == 1);

  assert(solve_015(0, 0) == 1);
  assert(solve_015(0, 1) == 1);
  assert(solve_015(0, 4) == 1);
  assert(solve_015(0, 9) == 1);

  assert(solve_015(0, 0) == 1);
  assert(solve_015(1, 0) == 1);
  assert(solve_015(3, 0) == 1);
  assert(solve_015(8, 0) == 1);

  assert(solve_015(1, 1) == 2);
  assert(solve_015(1, 3) == 4);
  assert(solve_015(1, 4) == 5);
  assert(solve_015(1, 9) == 10);

  assert(solve_015(1, 1) == 2);
  assert(solve_015(3, 1) == 4);
  assert(solve_015(6, 1) == 7);
  assert(solve_015(8, 1) == 9);
}

void test_solve_harder() {
  assert(solve_015(2, 2) == 6);
  assert(solve_015(2, 3) == 10);
  assert(solve_015(3, 2) == 10);
  assert(solve_015(5, 3) == 56);
  assert(solve_015(4, 4) == 70);
  assert(solve_015(3, 4) == 35);
}

void test_solve_big() {
  assert(solve_015(4, 6) == 210);
  assert(solve_015(5, 5) == 252);
  assert(solve_015(8, 4) == 495);
  assert(solve_015(5, 7) == 792);

  // this broke the solution before because I used uint32_t which is not
  // large enough, which resulted in an overflow.
  assert(solve_015(20, 16) == 7307872110);
}

