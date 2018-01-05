#include <euler/test.h>
#include "solve.h"

void test_truncatable()
{
    prime_t p = prime_new();

    assert(true == truncatable(&p, 3797));
    assert(true == truncatable(&p, 23));
    assert(false == truncatable(&p, 11));
    assert(false == truncatable(&p, 13));
    assert(false == truncatable(&p, 29));
    assert(false == truncatable(&p, 31));

    prime_free(&p);
}

void test_solve()
{
    prime_t p = prime_new();

    assert(23 == solve(1));

    prime_free(&p);
}

TESTS() {
    RUN(test_truncatable);
    RUN(test_solve);
}
