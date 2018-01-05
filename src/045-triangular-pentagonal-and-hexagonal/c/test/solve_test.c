#include <euler/test.h>
#include "solve.h"

void test_solve()
{
    assert(solve(0, 0, 0) == 1);
    assert(solve(200, 100, 100) == 40755);
}

TESTS() {
    RUN(test_solve);
}
