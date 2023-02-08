#include "stdio.h"

int main(int argc, char const *argv[])
{
    /* How to print 0x0000 */
    printf("%x\n", 0xFE);
    printf("%#x\n", 0xFE);
    printf("%#0x\n", 0xFE);
    printf("%#4x\n", 0xFE);
    printf("%#0.4x\n", 0xFE);

    printf("%#0.4x\n", 0);
    printf("0x%.4x\n", 0);
    return 0;
}
