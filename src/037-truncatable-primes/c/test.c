#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_truncatable();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_truncatable();
    printf("done.\n");

    return 0;
}

void test_truncatable()
{
    prime_t p = prime_new();
    while(prime_next(&p) < 4000) ;

    assert(true == truncatable(&p, 3797));
}
