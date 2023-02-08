// What about 0xFF to fputc
// FF becomes -1, becomes (int)-1, becomes unsigned char = what?

#include "stdio.h"

int main()
{
    unsigned char a = 0xFF;
    int b = a;
    unsigned char c = b;
    printf("unsigned %d %d %d\n", a, b, c);
    int B = fputc(b, stdout);
    printf("unsigned %d\n", B);

    // signed char d = 0xFF;
    signed char d = '\xFF';
    int e = d;
    unsigned char f = e;
    printf("signed %d %d %d\n", d, e, f);
    int E = fputc(b, stdout);
    printf("unsigned %d\n", E);


    return 0;
}
