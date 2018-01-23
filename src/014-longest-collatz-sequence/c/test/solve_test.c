#include "solve.h"
#include <euler/test.h>

void test_solve() { assert(9 == solve(10)); }

TESTS() { RUN(test_solve); }
