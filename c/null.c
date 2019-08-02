#include "stdio.h"
char test(char a[1])
{
    return a[1];
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("%c\n", test("x"));
    printf("%c\n", test("xbc"));
    printf("%c\n", test(""));
    printf("%c\n", test(NULL));
    return 0;
}
