#include <test.h>
#include "solve.h"

void test_permutations()
{
    assert(true == permutations(1234, 2341, 3412));
    assert(false == permutations(123, 2103, 2013));
}

TESTS() {
    RUN(test_permutations);
}
