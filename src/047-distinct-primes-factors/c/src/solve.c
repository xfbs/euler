#include "solve.h"

uint64_t solve(uint8_t count)
{
    prime_t primes = prime_new();
    uint16_t factors[count][count];

    uint64_t cur = 1;
    for(uint8_t bad = count; bad || !distinct_prime_factors(count, factors); cur++) {
        if(prime_factors(&primes, cur, count, factors[cur % count])) {
            if(bad) bad--;
        } else {
            bad = count;
        }
    }

    return cur - count;
}

bool prime_factors(prime_t *p, uint64_t num, uint8_t cnt, uint16_t f[cnt]) {
    size_t pos = 0;

    // for every prime, check if it's a factor of num, and if so adds it to `f`.
    for(size_t i = 0; num != 1; i++) {
        uint64_t prime = prime_nth(p, i);
        uint16_t product = 1;

        while(num % prime == 0) {
            product *= prime;;
            num /= prime;
        }

        if(product != 1) {
            // make sure there are not more than `cnt` prime factors
            if(pos == cnt) return false;

            f[pos] = product;
            pos++;
        }
    }

    // check if we got all `cnt` prime factors
    return pos == cnt;
}

bool distinct_prime_factors(uint8_t count, uint16_t factors[count][count]) {
    // pick any of the `count` numbers
    for(uint8_t num_a = 0; num_a < count; num_a++) {

        // pick any other of the `count` numbers, such that a > b
        for(uint8_t num_b = num_a + 1; num_b < count; num_b++) {

            // pick any of the factors
            for(uint8_t fac_a = 0; fac_a < count; fac_a++) {

                // pick any of the factors, such that a >= b (we can compare the
                // same factors for two different numbers)
                for(uint8_t fac_b = fac_a; fac_b < count; fac_b++) {
                    // if they are equal, the numbes don't have distinct prime
                    // factors.
                    if(factors[num_a][fac_a] == factors[num_b][fac_b]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
