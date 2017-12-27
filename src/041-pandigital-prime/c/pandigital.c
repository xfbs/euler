#include <stdio.h>
#include "pandigital.h"
#include "factorial.h"

uint32_t nth_pandigital(uint8_t n, uint32_t nth)
{
    // the finished pandigital
    uint32_t num = 0;

    // which digits are taken
    uint32_t taken = 0;

    while(n) {
        num *= 10;

        // which of the remaining digits we will take
        uint8_t choice = nth/factorial(n-1);
        nth -= choice * factorial(n-1);

        // find the remaining digit
        uint8_t digit = 0;
        while(choice != 0) {
            if(!(taken & (1 << digit))) choice--;
            digit++;
        }

        while(taken & (1 << digit)) {
            digit++;
        }

        // mark this digit as used
        taken |= 1 << digit;

        // digits are zero-indexed, but we treat '1' as first digit
        digit++;
        num += digit;
        n--;
    }

    return num;
}


