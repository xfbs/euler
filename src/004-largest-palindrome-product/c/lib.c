#include "lib.h"

uint32_t solve(size_t digits)
{
    uint32_t min = pow(10, digits-1);
    uint32_t max = pow(10, digits);
    uint32_t match = 0;

    for(uint32_t first = min; first < max; first++) {
        for(uint32_t second = first; second < max; second++) {
            uint32_t product = first * second;
            if(product > match && is_palindrome(product)) {
                match = product;
            }
        }
    }

    return match;
}

bool is_palindrome(uint32_t num)
{
    // reverse the number and compare against itself
    uint32_t original = num;
    uint32_t reversed = 0;

    while(num != 0) {
        reversed *= 10;
        reversed += num % 10;
        num /= 10;
    }

    return original == reversed;
}
