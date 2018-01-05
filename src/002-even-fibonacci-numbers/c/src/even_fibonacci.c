#include "euler/even_fibonacci.h"

uint64_t next_even_fibonacci(uint64_t fibo)
{
    return fibo * PHI3 + 0.5;
}
