#include <test.h>
#include "solve.h"

void test_chapernowne_digit()
{
    assert(champernowne_digit(0) == 1);
    assert(champernowne_digit(1) == 2);
    assert(champernowne_digit(2) == 3);
    assert(champernowne_digit(3) == 4);
    assert(champernowne_digit(4) == 5);
    assert(champernowne_digit(5) == 6);
    assert(champernowne_digit(6) == 7);
    assert(champernowne_digit(7) == 8);
    assert(champernowne_digit(8) == 9);
    assert(champernowne_digit(9) == 1);
    assert(champernowne_digit(10) == 0);
    assert(champernowne_digit(11) == 1);
    assert(champernowne_digit(12) == 1);
    assert(champernowne_digit(13) == 1);
    assert(champernowne_digit(14) == 2);
    assert(champernowne_digit(15) == 1);
    assert(champernowne_digit(16) == 3);
    assert(champernowne_digit(17) == 1);
    assert(champernowne_digit(18) == 4);
}

TESTS() {
    RUN(test_chapernowne_digit);
}
