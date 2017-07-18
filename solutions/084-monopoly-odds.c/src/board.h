#include "c21.h"
#pragma once

typedef union board {
    double squares[40];
    struct {
        double go;
        double a1;
        double cc1;
        double a2;
        double t1;
        double r1;
        double b1;
        double ch1;
        double b2;
        double b3;
        double jail;
        double c1;
        double u1;
        double c2;
        double c3;
        double r2;
        double d1;
        double cc2;
        double d2;
        double d3;
        double fp;
        double e1;
        double ch2;
        double e2;
        double e3;
        double r3;
        double f1;
        double f2;
        double u2;
        double f3;
        double g2j;
        double g1;
        double g2;
        double cc3;
        double g3;
        double r4;
        double ch3;
        double h1;
        double t2;
        double h2;
    } square;
    struct {
        double ignore[40];
        int num;
        int sides;
    } dice;
} board;

// creates a new board, setting all squares to the initial probability
void board_init(board *b, int num_dice, int dice_sides, double p);

// does one round of approximation on the probabilities for landing on each
// square on the board
void board_approx(board *b);

// normalizes the probabilities in the board to add up to 1
void board_normalize(board *b);
