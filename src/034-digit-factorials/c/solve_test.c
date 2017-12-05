#include <test.h>
#include "solve.h"

void test_is_curious_number() {
    assert(true == is_curious_number(145));
    assert(false == is_curious_number(10));
    assert(false == is_curious_number(12));
}

TESTS() {
    RUN(test_is_curious_number);
}
