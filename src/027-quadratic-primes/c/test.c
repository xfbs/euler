#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_quadratic_prime_run();
void test_solve();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_solve();
    test_quadratic_prime_run();
    printf("done.\n");

    return 0;
}

void test_quadratic_prime_run()
{
    prime_t p = prime_new();

    assert(40 == quadratic_prime_run(&p, 1, 41));
    assert(80 == quadratic_prime_run(&p, -79, 1601));
}

void test_solve()
{
    prime_t p = prime_new();

    assert(-126479 == solve(1700));
}
