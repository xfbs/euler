#include "solution.h"
#include <assert.h>
#include <stdio.h>

void test_solution();
void test_sum();
void test_gcd();
void test_lcm();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_lcm();
    test_gcd();
    test_sum();
    test_solution();
    printf("done.\n");

    return 0;
}

void test_solution()
{
    assert(solve(50, 10, 25) == 175);
    assert(solve(50, 25, 10) == 175);
    assert(solve(55, 10, 25) == 175);
    assert(solve(55, 25, 10) == 175);
    assert(solve(9, 3, 5) == 23);
}

void test_lcm()
{
    // gcd of primes a and b is always a*b
    assert(lcm(3, 5) == 15);
    assert(lcm(5, 13) == 65);

    assert(lcm(2, 10) == 10);
    assert(lcm(3, 10) == 30);
    assert(lcm(10, 25) == 50);
}

void test_gcd()
{
    assert(gcd(3, 5) == 1);
    assert(gcd(5, 13) == 1);
    assert(gcd(2, 10) == 2);
    assert(gcd(5, 10) == 5);
    assert(gcd(10, 25) == 5);
}

void test_sum()
{
    assert(sum_divisible(10, 3) == 18);
    assert(sum_divisible(10, 5) == 15);
    assert(sum_divisible(22, 7) == 42);
    assert(sum_divisible(43, 51) == 0);
    assert(sum_divisible(50, 10) == 150);
    assert(sum_divisible(50, 25) == 75);
}
