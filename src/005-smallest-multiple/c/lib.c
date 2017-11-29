#include "lib.h"

uint32_t solve(size_t max)
{
    uint32_t l = 1;

    for(uint32_t i = 2; i <= max; i++) {
        l = lcm(l, i);
    }

    return l;
}

// stolen from my solution to problem 1
uint32_t gcd(uint32_t a, uint32_t b)
{
    while(b != 0) {
        uint32_t t = b;
        b = a % b;
        a = t;
    }

    return a;
}

// stolen from my solution to problem 1
uint32_t lcm(uint32_t a, uint32_t b)
{
    if(b > a) return lcm(b, a);
    return a / gcd(a, b) * b;
}
