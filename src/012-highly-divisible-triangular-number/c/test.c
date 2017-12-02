#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_primes();
void test_factors();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_primes();
    test_factors();
    printf("done.\n");

    return 0;
}

void test_primes()
{
    prime_t p = prime_new();
    assert(p.primes != 0);
    assert(p.cur == 0);
    assert(p.cap > 0);
    assert(p.len == 2);

    assert(2 == prime_next(&p));
    assert(3 == prime_next(&p));
    prime_reset(&p);
    assert(2 == prime_next(&p));
    assert(3 == prime_next(&p));
    assert(5 == prime_next(&p));
    assert(7 == prime_next(&p));
    assert(11 == prime_next(&p));

    for(size_t i = 0; i < 512; i++) {
        assert(0 != prime_next(&p));
    }
}

void test_factors()
{
    prime_t p = prime_new();

    assert(factor_count(&p, 1) == 1);
    assert(factor_count(&p, 2) == 2);
    assert(factor_count(&p, 3) == 2);
    assert(factor_count(&p, 4) == 3);
    assert(factor_count(&p, 5) == 2);
    assert(factor_count(&p, 6) == 4);
    assert(factor_count(&p, 9) == 3);
    assert(factor_count(&p, 36) == 9);
}
