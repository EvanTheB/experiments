#include "stdio.h"

/* unsigned * signed converts signed to unsigned */

int main(int argc, char const *argv[])
{
    unsigned int u32 = 10;
    signed int s32 = -10;
    unsigned short u16 = 10;
    signed short s16 = -10;
    printf("%u %d\n", u32 * s32,  u32 * s32);
    printf("%u %d\n", u32 * s16,  u32 * s16);
    printf("%u %d\n", u16 * s32,  u16 * s32);
    return 0;
}
