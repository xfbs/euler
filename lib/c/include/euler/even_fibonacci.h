#include <stdint.h>
#include <math.h>
#pragma once

static const double PHI = 1.61803398875;
#define PHI3 (PHI * PHI * PHI)

uint64_t next_even_fibonacci(uint64_t fibo);
