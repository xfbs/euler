#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_solve();
void test_square_of_sums();
void test_sum_of_squares();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_square_of_sums();
    test_sum_of_squares();
    test_solve();
    printf("done.\n");

    return 0;
}

void test_solve()
{
    assert(solve(10) == 2640);
}

void test_square_of_sums()
{
    assert(1 == square_of_sums(1));
    assert(9 == square_of_sums(2));
    assert(36 == square_of_sums(3));
    assert(100 == square_of_sums(4));
    assert(225 == square_of_sums(5));
    assert(3025 == square_of_sums(10));
}

void test_sum_of_squares()
{
    assert(1 == sum_of_squares(1));
    assert(5 == sum_of_squares(2));
    assert(14 == sum_of_squares(3));
    assert(30 == sum_of_squares(4));
    assert(55 == sum_of_squares(5));
    assert(385 == sum_of_squares(10));
}
