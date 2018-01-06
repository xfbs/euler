#include <euler/test.h>
#include "solve.h"

void test_make_pandigital_multiple() {
    assert(make_pandigital_multiple(192, 3) == 192384576);
    assert(make_pandigital_multiple(9, 5) == 918273645);
    assert(make_pandigital_multiple(11, 3) == 112233);
}

void test_pandigital_multiple() {
    assert(pandigital_multiple(11) == 0);
    assert(pandigital_multiple(12) == 0);
    assert(pandigital_multiple(13) == 0);
    assert(pandigital_multiple(14) == 0);

    assert(pandigital_multiple(192) == 192384576);
    assert(pandigital_multiple(9) == 918273645);
}

void test_solve() {
    assert(solve() >= 123456789);
    assert(solve() <= 987654321);
}

TESTS() {
    RUN(test_make_pandigital_multiple);
    RUN(test_pandigital_multiple);
}
