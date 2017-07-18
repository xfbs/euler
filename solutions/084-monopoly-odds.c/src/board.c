#include "board.h"
#include "square.h"
#include <stdio.h>

void board_init(board *b, int num_dice, int dice_sides, double p) {
    forcount(square, BOARD_SQUARES) {
        b->squares[square] = p;
    }

    b->dice.num = num_dice;
    b->dice.sides = dice_sides;
}

void board_approx(board *b) {
    forcount(square, BOARD_SQUARES) {
        board_normalize(b);
        double old = b->squares[square];
        b->squares[square] = square_probability(b, square);
        printf("square = %i, old = %1.5f, new = %1.5f, change = %3.8f%%\n", (int)square, old, b->squares[square], 100 * old/b->squares[square] - 100);
    }
}


void board_normalize(board *b) {
    double total = 0;

    forcount(square, BOARD_SQUARES) {
        total += b->squares[square];
    }

    printf("correcting by a factor of %3.4f\n", 100 * (total-1));

    forcount(square, BOARD_SQUARES) {
        b->squares[square] /= total;
    }
}
