#include "solve.h"
#include "vec8.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        fprintf(stderr, "no datafile specified\n");
        return -1;
    }

    FILE *data_file = fopen(argv[1], "r");
    vec8_t v = vec8_new(0, 0);

    while(!feof(data_file)) {
        uint8_t c = fgetc(data_file);
        if(c < '0' || c > '9') continue;
        vec8_push(&v, c - '0');
    }

    printf("%llu\n", solve(&v, 13));

    return 0;
}
