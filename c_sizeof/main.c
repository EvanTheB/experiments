#include "stdio.h"
#include "limits.h"

#define do_it(type) printf("%s\t%d\n", #type, sizeof(type) * CHAR_BIT);

int main(int argc, char const *argv[])
{
    do_it(char);
    do_it(short);
    do_it(int);
    do_it(long);
    do_it(long long);
    do_it(void *);
    do_it(float);
    do_it(double);
    do_it(long double);
    return 0;
}
