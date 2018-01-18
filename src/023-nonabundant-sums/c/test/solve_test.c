#include <euler/test.h>
#include "solve.h"

void test_solve() {
    assert(solve(10) == 45);
    assert(solve(20) == 190);
    assert(solve(25) == 276);
    assert(solve(32) == 442);
}

TESTS() {
    RUN(test_solve);
}
