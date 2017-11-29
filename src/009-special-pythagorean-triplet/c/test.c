#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_solve();
void test_is_pythagorean_triplet();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_is_pythagorean_triplet();
    test_solve();
    printf("done.\n");

    return 0;
}

void test_solve()
{
    assert(60 == solve(12));
}

void test_is_pythagorean_triplet()
{
    assert(is_pythagorean_triplet(3, 4, 5) == true);
    assert(is_pythagorean_triplet(3, 4, 6) == false);
    assert(is_pythagorean_triplet(4, 3, 5) == false);
    assert(is_pythagorean_triplet(20, 21, 29) == true);
    assert(is_pythagorean_triplet(48, 55, 73) == true);
    assert(is_pythagorean_triplet(48, 55, 74) == false);
}
