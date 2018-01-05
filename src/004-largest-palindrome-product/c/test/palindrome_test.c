#include "euler/test.h"
#include "euler/palindrome.h"

void test_palin()
{
    assert(is_palindrome(101) == true);
    assert(is_palindrome(123) == false);
    assert(is_palindrome(404) == true);
    assert(is_palindrome(767) == true);
    assert(is_palindrome(999) == true);
    assert(is_palindrome(424) == true);
    assert(is_palindrome(11) == true);
    assert(is_palindrome(18) == false);
    assert(is_palindrome(1095901) == true);
    assert(is_palindrome(1047402) == false);
    assert(is_palindrome(6060) == false);
    assert(is_palindrome(123454321) == true);
}

TESTS() {
    RUN(test_palin);
}
