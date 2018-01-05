#include <euler/test.h>
#include "solve.h"

void test_solve()
{
    assert(3 == solve(1));
    assert(39 == solve(10));
    assert(864 == solve(100));
}

void test_number_letter_count()
{
    assert(3 == number_letter_count(1));
    assert(35 == number_letter_count(3451));
}

TESTS() {
    RUN(test_solve);
    RUN(test_number_letter_count);
}
