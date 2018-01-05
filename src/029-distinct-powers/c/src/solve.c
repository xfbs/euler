#include "solve.h"

uint32_t solve(uint32_t max_a, uint32_t max_b)
{
    uint32_t sum = (max_a-1) * (max_b-1);
    bitvec_t b = bitvec_new(max_a-1);

    for(uint32_t a = 2; a <= max_a; a++) {
        uint32_t product = a*a;
        uint32_t power = 2;
        while(product <= max_a && !bitvec_get(&b, product-2)) {
            bitvec_set(&b, product-2);

            for(uint32_t b = 2; b <= max_b; b++) {
                uint32_t exponent = b * power;

                for(uint32_t lower = 1; lower < power; lower++) {
                    if(((exponent % lower) == 0) && (exponent/lower) <= max_b) {
                        sum -= 1;
                        break;
                    }
                }
            }

            product *= a;
            power += 1;
        }
    }

    bitvec_free(&b);

    return sum;
}
