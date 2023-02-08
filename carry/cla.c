#include <stdio.h>

unsigned long cla_add(unsigned A, unsigned B)
{
    unsigned P = A | B;
    unsigned G = A & B;

    unsigned G2 = G | ((G << 1) & P);
    unsigned P2 = P & (P << 1);

    unsigned G4 = G2 | ((G2 << 2) & P2);
    unsigned P4 = P2 & (P2 << 2);

    unsigned G8 = G4 | ((G4 << 4) & P4);
    unsigned P8 = P4 & (P4 << 4);

    unsigned G16 = G8 | ((G8 << 8) & P8);
    unsigned P16 = P8 & (P8 << 8);

    unsigned G32 = G16 | ((G16 << 16) & P16);
    // unsigned P32 = P16 & (P16 << 16);

    // printf("%X\n", G32);

    unsigned long C = (A + B) & 0xFFFFFFFF;
    C += ((unsigned long)G32 & 0x80000000) << 1;
    return C;
}

unsigned long half_add(unsigned A, unsigned B)
{
    unsigned a = A & 0xFFFF;
    unsigned b = B & 0xFFFF;
    unsigned ol = a + b;

    a = (A >> 16) & 0xFFFF;
    b = (B >> 16) & 0xFFFF;
    unsigned oh = a + b + (ol >> 16);

    return (ol & 0xFFFF) | ((unsigned long)oh << 16);
}

unsigned long check_add(unsigned A, unsigned B)
{
    // check for WOULD overflow
    // A + B > N ?
    // A > N - B ?
    if (A > 0xFFFFFFFF - B)
    {
        return 0x100000000ULL + (A + B);
    }
    else
    {
        return A + B;
    }
}

unsigned long check_add2(unsigned A, unsigned B)
{
    // check for DID overflow
    // A + B < A || (A=0, B=0xFF)
    unsigned C = A + B;

    if (C < A || C < B)
    {
        return 0x100000000ULL + (A + B);
    }
    else
    {
        return A + B;
    }
}

int main(int argc, char const *argv[])
{
    // printf("%d %d\n", sizeof (unsigned), sizeof (unsigned long));
    // 0xFFFFFFFF
    // 0x80000000
    for (unsigned A = 0x7FFFFFFF; A != 0; ++A)
    {
        for (unsigned B = 0x3FFFFFFF; B != 0; ++B)
        {
            // unsigned long C = cla_add(A,B);
            // unsigned long C = half_add(A,B);
            unsigned long C = check_add2(A,B);
            unsigned long CC = (unsigned long)A + (unsigned long)B;
            if (C != CC)
            {
                printf("bad %X %X %LX %LX\n", A, B, C, CC);
            }
        }
    }

    // printf("%X %X %X %X\n", A, B, A+B, G32);

    return 0;
}
