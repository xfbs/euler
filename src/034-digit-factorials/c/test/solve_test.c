#include <euler/test.h>
#include "solve.h"

void test_is_curious_number() {
    assert(true == is_curious_number(145));
    assert(false == is_curious_number(10));
    assert(false == is_curious_number(12));
    assert(false == is_curious_number(19));
    assert(false == is_curious_number(9));
}

void test_solve() {
    assert(0 == solve(0));
    assert(0 == solve(1));
    assert(0 == solve(2));
    assert(0 == solve(3));
    assert(145 == solve(145));
}

TESTS() {
    RUN(test_is_curious_number);
    RUN(test_solve);
}
