#include "solve.h"

uint32_t solve(uint32_t n)
{
    return square_of_sums(n) - sum_of_squares(n);
}

uint32_t square_of_sums(uint32_t n)
{
    return (n*n) * ((n + 1) * (n + 1)) / 4;
}

uint32_t sum_of_squares(uint32_t n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}
