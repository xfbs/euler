#include "solve.h"

uint64_t solve(uint64_t max)
{
    uint64_t sum = 0;

    for(uint64_t num = 10; num < max; num++) {
        if(is_curious_number(num)) {
            sum += num;
        }
    }

    return sum;
}

static uint64_t factorial(uint64_t num)
{
    if(num == 0) return 1;
    return num * factorial(num - 1);
}

bool is_curious_number(uint64_t num)
{
    static uint64_t memo[10] = {0};
    uint64_t cur = num;
    uint64_t sum = 0;

    while(sum < num && cur) {
        uint8_t digit = cur % 10;
        if(!memo[digit]) memo[digit] = factorial(digit);
        sum += memo[digit];
        cur /= 10;
    }

    return (cur == 0) && (sum == num);
}
