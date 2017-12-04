#include "gcd_lcm.h"

uint64_t lcm(uint64_t a, uint64_t b)
{
    if(b > a) return lcm(b, a);
    return a / gcd(a, b) * b;
}

uint64_t gcd(uint64_t a, uint64_t b)
{
    while(b != 0) {
        uint64_t t = b;
        b = a % b;
        a = t;
    }

    return a;
}
