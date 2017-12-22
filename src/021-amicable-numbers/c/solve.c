#include <stdio.h>
#include "solve.h"

uint32_t solve(size_t max)
{
    bitvec_t b = bitvec_new(max);

    for(size_t i = 1; i < max; i++) {
        if(!bitvec_get(&b, i)) {
            uint32_t pair = amicable_pair(i);

            if(pair) {
                bitvec_set(&b, i);
                bitvec_set(&b, pair);
            }
        }
    }

    uint32_t sum = 0;
    for(size_t i = 1; i < max; i++) {
        if(bitvec_get(&b, i)) sum += i;
    }

    return sum;
}

uint32_t amicable_pair(uint32_t num) {
    uint32_t pair = divisor_sum(num);

    if(num != pair && num == divisor_sum(pair)) {
        return pair;
    } else {
        return 0;
    }
}


