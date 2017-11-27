#include "square.h"
#include <stdio.h>

square square_offset(square s, int offset) {
    int new = ((int)s) + offset;

    while(new < 0) {
        new += BOARD_SQUARES;
    }

    while(new >= BOARD_SQUARES) {
        new -= BOARD_SQUARES;
    }

    return new;
}

double square_probability(board *b, square s) {
    // probability of getting here by rolling the dice
    double p = square_roll(b, s);

    // three consecutive doubles
    double roll_double_p = 1.0/(double)b->dice.sides;
    double roll_three_doubles_p = pow(roll_double_p, 3);

    // special probabilities
    double sixteenth = 1.0/16.0;
    double chest = b->square.cc1 + b->square.cc2 + b->square.cc3;
    double chance = b->square.ch1 + b->square.ch2 + b->square.ch3;

    double tmp = 0;

    switch(s) {
        case GO:    p += chest  * sixteenth; // chest  card 1
                    p += chance * sixteenth; // chance card 1
                    break;

        case JAIL:  tmp += b->square.g2j;      // go to jail square
                    tmp += chest  * sixteenth; // chest  card 2
                    tmp += chance * sixteenth; // chance card 2
                    p += roll_three_doubles_p * (1 - tmp);
                    p += tmp;
                    break;

        case C1:    p += chance * sixteenth; // chance card 3
                    break;

        case CC3:   p += b->square.ch3 * sixteenth; // chance card 10 (ch3)
                    break;

        case D3:    p += b->square.ch2 * sixteenth; // chance card 10 (ch2)
                    break;

        case E3:    p += chance * sixteenth; // chance card 4
                    break;

        case H2:    p += chance * sixteenth; // chance card 5
                    break;

        case R1:    p += chance * sixteenth; // chance card 6
                    p += b->square.ch3 * sixteenth * 2; // chance card 7-8 (ch3)
                    break;

        case R2:    p += b->square.ch1 * sixteenth * 2; // chance card 7-8 (ch1)
                    break;

        case R3:    p += b->square.ch2 * sixteenth * 2; // chance card 7-8 (ch2)
                    break;

        case T1:    p += b->square.ch1 * sixteenth; // chance card 10 (ch1)
                    break;

        case U1:    p += b->square.ch1 * sixteenth; // chance card 9 (ch1)
                    p += b->square.ch3 * sixteenth; // chance card 9 (ch3)
                    break;

        case U2:    p += b->square.ch2 * sixteenth; // chance card 9 (ch2)
                    break;

        default:    break;
    }

    return p;
}

double square_advance(board *b, square s) {
    double p = b->squares[s];

    // probability to advance from a community chest
    double chest = 7.0/8.0;

    // probability to advance from a chance square
    double chance = 3.0/8.0;

    switch(s) {
        case G2J: return 0;
        case CH1:
        case CH2:
        case CH3: return p * chance;
        case CC1:
        case CC2:
        case CC3: return p * chest;
        default:  return p;
    }
}

double square_roll(board *b, square s) {
    int dice_possibilities = b->dice.sides * b->dice.sides;
    double roll_p = 1.0/(double)dice_possibilities;
    double roll_two_doubles_p = 1 - pow(1.0/(double)b->dice.sides, 2);
    double p = 0;

    for(int dice_a = 1; dice_a <= b->dice.sides; dice_a++){
        for(int dice_b = 1; dice_b <= b->dice.sides; dice_b++) {
            square origin = square_offset(s, -dice_a -dice_b);

            if(dice_a != dice_b) {
                p += roll_p * square_advance(b, origin);
            } else {
                p += roll_p * square_advance(b, origin) * roll_two_doubles_p;
            }
        }
    }

    return p;
}
