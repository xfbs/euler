#include "test.h"
#include "gcd_lcm.h"

void test_lcm()
{
    // gcd of primes a and b is always a*b
    assert(lcm(3, 5) == 15);
    assert(lcm(5, 13) == 65);

    assert(lcm(2, 10) == 10);
    assert(lcm(3, 10) == 30);
    assert(lcm(10, 25) == 50);
}

void test_gcd()
{
    assert(gcd(3, 5) == 1);
    assert(gcd(5, 13) == 1);
    assert(gcd(2, 10) == 2);
    assert(gcd(5, 10) == 5);
    assert(gcd(10, 25) == 5);
}

TESTS() {
    RUN(test_lcm);
    RUN(test_gcd);
}
