#include <euler/simple_prime.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include "euler/factorial.h"
#include "euler/pandigital.h"
#include "solve.h"

static bool prime_check(prime_t *p, uint32_t num)
{
    uint32_t root = sqrt(num);

    for(size_t i = 0; prime_nth(p, i) < root; i++) {
        if((num % prime_nth(p, i)) == 0) {
            return false;
        }
    }

    return true;
}

uint32_t solve(uint8_t max)
{
    prime_t p = prime_new();

    for(uint8_t n = max; n > 0; n--) {
        for(uint32_t nth = factorial(n); nth != 0; nth--) {
            uint32_t pan = nth_pandigital(n, nth-1);
            if(prime_check(&p, pan)) return pan;
        }
    }

    return 0;
}
