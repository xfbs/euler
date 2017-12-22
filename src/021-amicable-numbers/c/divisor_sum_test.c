#include "test.h"
#include "divisor_sum.h"

void test_divisor_sum() {
    assert(divisor_sum(2) == 1);
    assert(divisor_sum(3) == 1);
    assert(divisor_sum(4) == 1+2);
    assert(divisor_sum(5) == 1);
    assert(divisor_sum(6) == 1+2+3);
    assert(divisor_sum(7) == 1);
    assert(divisor_sum(8) == 1+2+4);
    assert(divisor_sum(9) == 1+3);
    assert(divisor_sum(10) == 1+2+5);
    assert(divisor_sum(11) == 1);
    assert(divisor_sum(12) == 1+2+3+4+6);
    assert(divisor_sum(220) == 284);
    assert(divisor_sum(284) == 220);
}

TESTS() {
    RUN(test_divisor_sum);
}
