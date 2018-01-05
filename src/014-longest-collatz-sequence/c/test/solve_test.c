#include <euler/test.h>
#include "solve.h"

void test_solve()
{
    assert(9 == solve(10));
}

TESTS() {
    RUN(test_solve);
}
