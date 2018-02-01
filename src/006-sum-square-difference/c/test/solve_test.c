#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() { assert(solve(10) == 2640); }

TESTS() { RUN(test_solve); }
