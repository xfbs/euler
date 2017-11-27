#include "solution.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

u64 pow_mod(u64 num, u64 exp, u64 mod)
{
    if(exp == 1) {
        // num^1 % mod == num % mod
        return num % mod;
    } else {
        // this is (num*num)^(floor(exp/2)) % mod
        u64 res = pow_mod(mult_mod(num, num, mod), exp/2, mod);

        if((exp % 2) == 1) {
            // num^(2e+1) % mod == num*(num*num)^e % mod
            return mult_mod(res, num, mod);
        } else {
            // num^(2e) % mod == (num*num)^e % mod
            return res % mod;
        }
    }
}

u64 mult_mod(u64 a, u64 b, u64 mod)
{
    // if numbers are small enough, just
    // multiply them now
    if((flsll(a) + flsll(b)) < 64) {
        return (a * b) % mod;
    }

    // extract high and low parts of numbers
    u64 ah = a >> 32;
    u64 bh = b >> 32;
    u64 al = a & (((u64)1 << 32) -1);
    u64 bl = b & (((u64)1 << 32) -1);

    u64 res = 0;
    res += (al * bl) % mod;
    res += shift_mod((al * bh) % mod, 32, mod);
    res %= mod;
    res += shift_mod((ah * bl) % mod, 32, mod);
    res %= mod;
    res += shift_mod((ah * bh) % mod, 64, mod);
    res %= mod;

    return res;
}

u64 shift_mod(u64 num, u8 amount, u64 mod)
{
    num %= mod;

    u8 num_size = flsll(num);
    if(num_size + amount < 64) {
        return (num << amount) % mod;
    } else {
        u8 space = 64 - num_size;
        assert(space != 0);

        return shift_mod(num << space, amount-space, mod);
    }
}

u64 sum_mod(u64 num[], size_t len, u64 mod)
{
    u64 sum = 0;

    forcount(i, len) {
        sum = (sum + (num[i] % mod)) % mod;
    }

    return sum;
}

u64 solve(u64 max, u64 digits)
{
    u64 mod = pow(10, digits);
    u64 series[max];

    forcount(num, max) {
        series[num] = pow_mod(num+1, num+1, mod);
    }

    return sum_mod(series, max, mod);
}
