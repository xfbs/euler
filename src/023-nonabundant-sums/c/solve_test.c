#include <test.h>
#include "solve.h"

void test_divisor_sum() {
    assert(divisor_sum(10) == 8);
    assert(divisor_sum(12) == 16);
    assert(divisor_sum(220) == 284);
    assert(divisor_sum(284) == 220);
}

void test_solve() {
}

TESTS() {
    RUN(test_divisor_sum);
    RUN(test_solve);
}
