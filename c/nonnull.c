#include "stdio.h"

static int foo(int x[static 1])
{
    return x[0];
}

__attribute__((__nonnull__))
static int foo2( int *x)
{
    return x[0];
}

static int foo3( int *x)
{
    if (!(x)) __builtin_trap();
    return x[0];
}



int main(int argc, char const *argv[])
{
    int *bar = NULL;

    // foo(&argc);
    // foo(bar);

    // foo2(&argc);
    // foo2(bar);

    foo3(&argc);
    foo3(bar);
    return 0;
}
