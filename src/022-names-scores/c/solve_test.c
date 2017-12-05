#include <test.h>
#include "solve.h"

void test_weight()
{
    assert(weight("COLIN") == 53);
    assert(weight("A") == 1);
    assert(weight("Z") == 26);
    assert(weight("AY") == 26);
}

TESTS() {
    RUN(test_weight);
}
