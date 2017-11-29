#include "lib.h"
#include <assert.h>
#include <stdio.h>

void test_solve();
void test_palin();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_palin();
    test_solve();
    printf("done.\n");

    return 0;
}

void test_solve()
{
    //...
}

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

