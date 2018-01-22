#include "euler/factorial.h"

uint64_t factorial(uint8_t nth)
{
    static uint64_t cache[18] = {0};
    if(nth <= 1) return 1;

    if(nth <= 20) {
        if(!cache[nth-2]) cache[nth-2] = factorial(nth-1) * nth;

        return cache[nth-2];
    } else {
        // 21! can't be represented in a uint64_t, this is an overflow.
        return 0;
    }
}
