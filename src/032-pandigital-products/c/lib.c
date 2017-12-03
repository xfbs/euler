#include "lib.h"

uint32_t solve()
{
    size_t len = 256;
    size_t pos = 0;
    uint32_t *list = calloc(len, sizeof(uint32_t));

    for(uint32_t a = 1; a < 999; a++) {
        for(uint32_t b = a; b < 9999; b++) {
            uint32_t p = pandigital_product(a, b);
            if(p != 0) {
                bool exists = false;
                for(size_t i = 0; i < pos; i++) {
                    if(list[i] == p) exists = true;
                }

                if(!exists) {
                    list[pos] = p;
                    pos++;
                }

                if(pos == len) {
                    len *= 2;
                    list = realloc(list, len * sizeof(uint32_t));
                }
            }
        }
    }

    uint32_t sum = 0;
    for(size_t i = 0; i < pos; i++) {
        sum += list[i];
    }

    return sum;
}

uint32_t pandigital_product(uint32_t a, uint32_t b)
{
    uint32_t nums = 0;
    uint32_t s, sum = a * b;
    s = sum;

    for( ; a > 0; a /= 10) {
        if(nums & (1<<(a%10))) return 0;
        nums |= (1<<(a%10));
    }

    for( ; b > 0; b /= 10) {
        if(nums & (1<<(b%10))) return 0;
        nums |= (1<<(b%10));
    }

    for( ; s > 0; s /= 10) {
        if(nums & (1<<(s%10))) return 0;
        nums |= (1<<(s%10));
    }

    return (nums == ((1<<10) - 2)) ? sum : 0;
}
