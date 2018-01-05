#include "solve.h"

uint32_t solve(size_t max)
{
    uint32_t l = 1;

    for(uint32_t i = 2; i <= max; i++) {
        l = lcm(l, i);
    }

    return l;
}
