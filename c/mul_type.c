#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* what is the type of * */
    unsigned a,b,r;
    unsigned long long r2;

    a = UINT32_MAX - 1;
    b = 2;

    printf("%u\n", a);
    printf("%u\n", a*b);
    printf("%llu\n", a*b);

    r = a * b;
    printf("%u\n", r);

    r2 = a * b;
    printf("%llu\n", r2);

    r2 = (unsigned long long)a * b;
    printf("%llu\n", r2);

    return 0;
}
