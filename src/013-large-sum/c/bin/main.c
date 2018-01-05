#include <euler/vec.h>
#include <stdbool.h>
#include <stdio.h>
#include "solve.h"

int main(int argc, char *argv[])
{
    if(argc < 2) {
        fprintf(stderr, "no data file specified");
        return -1;
    }

    FILE *data_file = fopen(argv[1], "r");
    vec_t v = vec_new(0, NULL);
    char *str;

    while(true) {
        str = malloc(256);

        if(1 == fscanf(data_file, "%255[0-9]%*255[^0-9]", str)) {
            vec_push(&v, str);
        } else {
            break;
        }
    }

    printf("%llu\n", solve(&v));

    return 0;
}
