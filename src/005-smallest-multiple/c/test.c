#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_solve();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_solve();
    printf("done.\n");

    return 0;
}

void test_solve()
{
    assert(solve(0) == 1);
    assert(solve(1) == 1);
    assert(solve(2) == 2);
    assert(solve(3) == 6);
    assert(solve(10) == 2520);
}
