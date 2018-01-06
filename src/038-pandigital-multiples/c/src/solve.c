#include <euler/bitvec.h>
#include "solve.h"

uint64_t solve()
{
    uint64_t max = 0;

    for(uint32_t base = 0; base < 10000; base++) {
        uint64_t pm = pandigital_multiple(base);

        if(pm > max) max = pm;
    }

    return max;
}

uint64_t make_pandigital_multiple(uint32_t base, uint8_t n) {
    uint64_t out = base;

    for(uint8_t c = 2; c <= n; c++) {
        uint64_t num = base * c;
        uint64_t cur = num;

        while(cur != 0) {
            out *= 10;
            cur /= 10;
        }

        out += num;
    }

    return out;
}

uint64_t pandigital_multiple(uint32_t base)
{
    bitvec_t taken = bitvec_new(10);

    for(uint8_t n = 1; n < 10; n++) {
        uint32_t num = base * n;

        while(num != 0) {
            if((num % 10) == 0 || bitvec_get(&taken, num % 10)) {
                bitvec_free(&taken);
                return 0;
            }

            bitvec_set(&taken, num % 10);
            num /= 10;
        }

        if(n > 1) {
            for(uint8_t digit = 1; digit < 10; digit++) {
                if(!bitvec_get(&taken, digit)) {
                    num = 1;
                }
            }

            if(num == 0) {
                bitvec_free(&taken);
                return make_pandigital_multiple(base, n);
            }
        }
    }

    bitvec_free(&taken);
    return 0;
}
