#include <test.h>
#include "solve.h"

void test_truncatable()
{
    prime_t p = prime_new();

    // gen primes
    prime_nth(&p, 4000);

    assert(true == truncatable(&p, 3797));
}

TESTS() {
    RUN(test_truncatable);
}
