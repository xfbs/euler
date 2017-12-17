#include <test.h>
#include "solve.h"

void test_solve()
{
    assert(solve(10) == 2640);
}

TESTS() {
    RUN(test_solve);
}
