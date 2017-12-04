#include <test.h>
#include "solve.h"

void test_divisor_sum() {
    assert(divisor_sum(10) == 8);
    assert(divisor_sum(220) == 284);
    assert(divisor_sum(284) == 220);
}

void test_amicable_pair() {
    assert(amicable_pair(10) == 0);
    assert(amicable_pair(220) == 284);
    assert(amicable_pair(284) == 220);
}

TESTS() {
    RUN(test_divisor_sum);
    RUN(test_amicable_pair);
}
