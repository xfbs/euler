#include <euler/test.h>
#include "solve.h"

void test_prime_factors() {
    prime_t p = prime_new();
    uint16_t f[3];

    assert(prime_factors(&p, 2*3*5, 3, f) == true);
    assert(f[0] == 2 && f[1] == 3 && f[2] == 5);

    assert(prime_factors(&p, 2*3*3, 3, f) == false);
    assert(prime_factors(&p, 2*3*5*7, 3, f) == false);

    assert(prime_factors(&p, 2*2*3*3*5*5, 3, f) == true);
    assert(f[0] == 4 && f[1] == 9 && f[2] == 25);
}

void test_solve() {
    assert(solve(2) == 14);
    assert(solve(3) == 644);
}

TESTS() {
    RUN(test_prime_factors);
    RUN(test_solve);
}
