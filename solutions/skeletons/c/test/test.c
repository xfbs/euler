#include "solution.h"
#include <assert.h>
#include <stdio.h>

void test_solution();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_solution();
    printf("done.\n");

    return 0;
}

void test_solution()
{
    assert(solve(0) == 0);
}
