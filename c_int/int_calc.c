#include "stdio.h"

/* are operations on small ints actually done on int intermediates? */

int main(int argc, char const *argv[])
{
    unsigned char A = 0xFF;
    unsigned char B = 0x02;
    unsigned int C = A * B;
    printf("%x %x\n", A*B, C);
    return 0;
}
