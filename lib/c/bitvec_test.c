#include "bitvec.h"
#include <assert.h>
#include <stdio.h>

void test_bitvec_new();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_bitvec_new();
    printf("done.\n");

    return 0;
}

void test_bitvec_new() {
    bitvec_t b = bitvec_new(100);
    assert(true);
}

