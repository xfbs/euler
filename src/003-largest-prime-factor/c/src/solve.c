#include "solve.h"
#define prime(x) shitty_primality_test(x)

uint64_t solve(uint64_t num) {
    uint64_t cur = 2;
    while(!prime(num)) {
        if((num % cur) == 0) {
            num /= cur;
        } else {
            do {
                cur += 1;
            } while(!prime(cur));
        }
    }

    return num;
}

// really inefficient primality test, but works okay for small numbers. checks
// all odd divisors from three to sqrt(num). slow but correct.
bool shitty_primality_test(uint64_t num)
{
    uint64_t max_check = ceil(sqrt(num));
    if(num < 2) return false;
    if(num > 2 && (num % 2) == 0) return false;
    for(uint64_t i = 3; i <= max_check; i += 2) {
        if((num % i) == 0) {
            return false;
        }
    }

    return true;
}

