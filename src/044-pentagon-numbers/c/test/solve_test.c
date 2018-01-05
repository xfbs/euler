#include <euler/test.h>
#include "solve.h"

void test_pentagon_number()
{
    assert(1 == p(1));
    assert(5 == p(2));
    assert(12 == p(3));
    assert(22 == p(4));
    assert(35 == p(5));
    assert(51 == p(6));
}

void test_pentagon_inverse()
{
    assert(1 == p_inverse(1));
    assert(2 == p_inverse(5));
    assert(3 == p_inverse(12));
    assert(4 == p_inverse(22));
    assert(5 == p_inverse(35));
    assert(6 == p_inverse(51));
    assert(7 == p_inverse(70));
}

void test_is_pentagon_number()
{
    assert(is_p(1));
    assert(is_p(5));
    assert(is_p(12));
    assert(is_p(22));
    assert(is_p(35));
    assert(is_p(51));
    assert(is_p(70));

    assert(!is_p(2));
    assert(!is_p(3));
    assert(!is_p(4));
    assert(!is_p(6));
    assert(!is_p(7));
    assert(!is_p(8));
    assert(!is_p(9));
    assert(!is_p(10));
    assert(!is_p(11));
    assert(!is_p(13));
    assert(!is_p(14));
    assert(!is_p(15));
    assert(!is_p(21));
    assert(!is_p(23));
    assert(!is_p(30));
    assert(!is_p(50));
    assert(!is_p(121));
}

void test_base()
{
    assert(4 == b(1));
    assert(11 == b(2));
    assert(21 == b(3));
    assert(34 == b(4));
}

TESTS() {
    RUN(test_pentagon_number);
    RUN(test_pentagon_inverse);
    RUN(test_is_pentagon_number);
    RUN(test_base);
}
