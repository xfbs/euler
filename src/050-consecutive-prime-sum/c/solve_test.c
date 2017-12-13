#include <test.h>
#include "solve.h"

void test_solve()
{
    assert(41 == solve(100));
    assert(953 == solve(1000));
}

TESTS() {
    RUN(test_solve);
}
