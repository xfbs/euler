#include "lib.h"

uint64_t str_chop(char str[], size_t len)
{
    if(strlen(str) < len) {
        str[len] = '\0';
    }

    return atoll(str);
}

uint64_t int_chop(uint64_t num, size_t len)
{
    size_t size = 0;
    uint64_t mag = 1;
    while(mag >= num) {
        mag *= 10;
        size += 1;
    }

    while(size > len) {
        size--;
        num /= 10;
    }

    return num;
}
