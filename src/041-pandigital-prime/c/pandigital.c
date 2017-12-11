#include "pandigital.h"
#include <stdio.h>

uint32_t nth_pandigital(uint8_t n, uint32_t nth)
{
    if(nth >= factorial(n)) return 0;

    // the finished pandigital
    uint32_t num = 0;

    // which digits are taken
    bitvec_t b = bitvec_new(n);

    while(n) {
        num *= 10;

        // which of the remaining digits we will take
        uint8_t choice = nth/factorial(n-1);
        nth -= choice * factorial(n-1);

        // find the remaining digit
        uint8_t digit = 0;
        while(choice != 0) {
            if(!bitvec_get(&b, digit)) choice--;
            digit++;
        }

        while(bitvec_get(&b, digit)) {
            digit++;
        }

        // mark this digit as used
        bitvec_set(&b, digit);

        // digits are zero-indexed, but we treat '1' as first digit
        digit++;
        num += digit;
        n--;
    }

    bitvec_free(&b);

    return num;
}


