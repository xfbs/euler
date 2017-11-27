#include "c21.h"
#include "board.h"
#include <math.h>
#pragma once

typedef enum square {
    GO,   /* go */
    A1,
    CC1,  /* community chest */
    A2,
    T1,
    R1,
    B1,
    CH1,  /* chance */
    B2,
    B3,
    JAIL, /* jail */
    C1,
    U1,
    C2,
    C3,
    R2,
    D1,
    CC2,  /* community chest */
    D2,
    D3,
    FP,
    E1,
    CH2,  /* chance */
    E2,
    E3,
    R3,
    F1,
    F2,
    U2,
    F3,
    G2J,  /* go to jail */
    G1,
    G2,
    CC3,  /* community chest */
    G3,
    R4,
    CH3,  /* community chest */
    H1,
    T2,
    H2,
    BOARD_SQUARES,
    NO_SQUARE
} square;

// the probability of hitting the square s
double square_probability(board *b, square s);

// the probability of advancing from the given square
double square_advance(board *b, square s);

// the probability of getting to this square by rolling the dice
double square_roll(board *b, square s);

// get the square offset by offset amounts from s
square square_offset(square s, int offset);
