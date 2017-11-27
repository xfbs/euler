#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "c21.h"
#pragma once

// computes pow(num, ext) % mod
u64 pow_mod(u64 num, u64 exp, u64 mod);

// computers (num[0] + num[1] ... + num[len-1]) % mod
u64 sum_mod(u64 num[], size_t len, u64 mod);

// computes (a * b) % mod
u64 mult_mod(u64 a, u64 b, u64 mod);

// computes (num << amount) % mod
u64 shift_mod(u64 num, u8 amount, u64 mod);

u64 solve(u64 max, u64 digits);
