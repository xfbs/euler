#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_collatz();
void test_solve();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_collatz();
    test_solve();
    printf("done.\n");

    return 0;
}

void test_collatz()
{
    collatz_cache_t cache = collatz_cache(1000);
    assert(1 == collatz_length(1, cache));
    assert(2 == collatz_length(2, cache));
    assert(10 == collatz_length(12, cache));
    assert(6 == collatz_length(32, cache));
    assert(17 == collatz_length(7, cache));
    free(cache.table);
}

void test_solve()
{
    assert(9 == solve(10));
}

