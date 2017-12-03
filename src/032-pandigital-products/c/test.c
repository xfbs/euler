#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_pandigital_product();
void test_solve();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_solve();
    test_pandigital_product();
    printf("done.\n");

    return 0;
}

void test_pandigital_product()
{
    assert(pandigital_product(1, 1) == 0);
    assert(pandigital_product(39, 186) == 7254);
    assert(pandigital_product(40, 186) == 0);
    assert(pandigital_product(38, 186) == 0);
    assert(pandigital_product(39, 185) == 0);
    assert(pandigital_product(39, 187) == 0);
}

void test_solve()
{
}
