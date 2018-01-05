#include <euler/test.h>
#include "solve.h"

void test_solve() {
    assert(solve(4) == 4231);
}

TESTS() {
    RUN(test_solve);
}
