#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_solve();
void test_fibos();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_fibos();
    test_solve();
    printf("done.\n");

    return 0;
}

void test_solve()
{
    assert(solve(90) == 44);
    assert(solve(700) == 798);
}

void test_fibos()
{
    assert((int)next_even_fibonacci(2) == 8);
    assert((int)next_even_fibonacci(8) == 34);
    assert((int)next_even_fibonacci(34) == 144);
    assert((int)next_even_fibonacci(144) == 610);

    for(double cur = 2; cur < 1000000; cur = next_even_fibonacci(cur)) {
        // make sure it's even
        assert((((int)cur)&1) == 0);
    }
}

