#include <stdbool.h>
#include <stdlib.h>
#include <euler/vec16.h>
#include "solve.h"

uint32_t solve()
{
    vec16_t products = vec16_new(0, 0);

    for(uint32_t a = 1; a < 99; a++) {
        for(uint32_t b = a; b < 9999; b++) {
            uint32_t p = pandigital_product(a, b);
            if(p != 0) {
                if(SIZE_MAX == vec16_index(&products, p)) {
                    vec16_push(&products, p);
                }
            }
        }
    }

    return vec16_sum(&products);
}

uint32_t pandigital_product(uint32_t a, uint32_t b)
{
    bool digits[10] = {false};
    uint32_t product = a * b;
    uint32_t p = product;

    for( ; a > 0; a /= 10) {
        if(digits[a % 10]) return 0;
        digits[a % 10] = true;
    }

    for( ; b > 0; b /= 10) {
        if(digits[b % 10]) return 0;
        digits[b % 10] = true;
    }

    for( ; p > 0; p /= 10) {
        if(digits[p % 10]) return 0;
        digits[p % 10] = true;
    }

    for(size_t digit = 0; digit < 10; digit++) {
        if(digits[digit] == (digit == 0)) {
            return 0;
        }
    }

    return product;
}
