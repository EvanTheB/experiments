// what do signed promotions do.

#include "stdio.h"

int main()
{
    unsigned char i = 1;
    ssize_t o = i;
    printf("%u %zd\n", i, o);

    i = 0xFF;
    o = i;
    printf("%u %zd\n", i, o);

    i = -1;
    o = i;
    printf("%u %zd\n", i, o);

    return 0;
}
