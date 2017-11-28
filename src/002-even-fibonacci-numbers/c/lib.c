#include "lib.h"

int solve(int max)
{
    double cur = 2;
    double sum = 0;

    while(cur < max) {
        sum += cur;
        cur = next_even_fibonacci(cur);
    }

    return (int)sum;
}

double next_even_fibonacci(double fibo)
{
    return round(fibo * PHI3);
}
