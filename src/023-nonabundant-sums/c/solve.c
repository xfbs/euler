#include "solve.h"

uint32_t solve(size_t max)
{
    bitvec_t poss = bitvec_new(max);
    uint32_t abundant[max];
    size_t pos = 0;

    for(size_t i = 1; i < max; i++) {
        if(divisor_sum(i) > i) {
            abundant[pos] = i;
            pos++;
        }
    }

    for(size_t a = 0; a < pos; a++) {
        for(size_t b = a; b < pos; b++) {
            uint32_t sum = abundant[a] + abundant[b];
            if(sum < max) {
                bitvec_set(&poss, sum);
            }
        }
    }

    uint32_t sum = 0;
    for(size_t i = 0; i < max; i++) {
        if(!bitvec_get(&poss, i)) {
            sum += i;
        }
    }

    return sum;
}
