#include "c.h"

int afunc(int y)
{
    return myfunc(2.0);
}

int bfunc(int);

int main(int argc, char const *argv[])
{
    afunc(1);
    bfunc(2);
    return 0;
}
