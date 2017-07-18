#include "solution.h"
#include "board.h"
#include "square.h"
#include <assert.h>
#include <stdio.h>

void test_solution();
void test_square_offset();

int main(int argc, char *argv[])
{
    printf("Testing solution...\n");
    test_solution();
    test_square_offset();
    printf("done.\n");

    return 0;
}

void test_solution()
{
    //assert(solve(0) == 0);

    board b;
    board_init(&b, 2, 4, 0.001);
    b.square.go = 0.025;

    forcount(i, 10000) {
        board_approx(&b);
    }
    //board_normalize(&b);

    forcount(square, BOARD_SQUARES) {
        printf("[%2i] = %1.4f\n", (int)square, b.squares[square]);
    }
}

void test_square_offset() {
    assert(square_offset(R1, 2) == CH1);
    assert(square_offset(F2, -5) == CH2);
    assert(square_offset(CC1, -4) == T2);
    assert(square_offset(R4, 10) == R1);
}
