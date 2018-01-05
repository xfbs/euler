#include "solve.h"

int solve(int max, int div1, int div2)
{
    return sum_divisible(max, div1)
        + sum_divisible(max, div2)
        - sum_divisible(max, lcm(div1, div2));
}

int sum_divisible(int max, int divisor)
{
    // smallest number lower than max that is
    // divisible by divisor
    int bound = max - (max % divisor);

    return (bound * ((bound / divisor) + 1)) / 2;
}