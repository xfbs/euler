#include "lib.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        fprintf(stderr, "no data file specified");
        return -1;
    }

    FILE *datafile = fopen(argv[1], "r");

    long long number, ignore, sum = 0;

    // add upp all the numbers
    while(0 < fscanf(datafile, "%11lld%lld", &number, &ignore)) {
        sum += number;
    }

    // get first ten digits from sum
    while(sum > 9999999999LL) {
        sum /= 10;
    }

    printf("%10lli\n", sum);

    return 0;
}
