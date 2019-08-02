#include "stdio.h"
int main(int argc, char const *argv[])
{
    union x {
        int a;
        int b;
    };

    union x val;
    val.a=1;


    union x val2 = val;

    printf("%d\n", val2.b);
    return 0;
}
