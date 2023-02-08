#include "stdio.h"
#include "limits.h"
#include "stdint.h"

#define do_it(type) printf("%s\t%d\n", #type, sizeof(type) * CHAR_BIT)
#define do3(size) do_it(int ##size## _t); \
    do_it(int_least ##size## _t); \
    do_it(int_fast ##size## _t)

int main(int argc, char const *argv[])
{
    do3(8);
    do3(16);
    do3(32);
    do3(64);

    do_it(intptr_t);
    do_it(intmax_t);
    return 0;
}
