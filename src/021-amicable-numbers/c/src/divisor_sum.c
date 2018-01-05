#include <math.h>
#include "euler/divisor_sum.h"

uint32_t divisor_sum(uint32_t num)
{
    uint32_t sum = 0;

    for(uint32_t i = 1; i <= (uint32_t)sqrt(num); i++) {
        if((num % i) == 0) {
            sum += i;
            if(i != (num / i) && i != 1) {
                sum += (num / i);
            }
        }
    }

    return sum;
}
