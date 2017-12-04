#include "solve.h"

int32_t solve(int32_t max)
{
    int32_t product = 1;
    uint32_t run = 0;
    prime_t p = prime_new();

    for(int32_t a = (-max + 5); a < max; a+=2) {
        // b must be odd, so we start at an odd number (this assumes that max
        // is even) and increase by two each iteration.
        // b must be positive, because when n=0, n^2+na+b shortens to just b.
        // a+b+1 >= 5 must be true
        for(int32_t b = -a+4; b < max; b+=2) {

            uint32_t cur = quadratic_prime_run(&p, a, b);
            if(cur > run) {
                run = cur;
                product = a * b;
            }
        }
    }

    return product;
}

uint32_t quadratic_prime_run(prime_t *p, int32_t a, int32_t b)
{
    uint32_t prime, run = 0;
    int32_t num = run*run + run*a + b;
    size_t i = 0;

    do {
        prime = prime_nth(p, i);
        i++;

        if(num == prime) {
            run++;
            num = run*run + run*a + b;

            while(num <= prime && prime > 2) {
                i--;
                prime = prime_nth(p, i);
            }
        }
    } while(num > 2 && prime < num);

    return run;
}
