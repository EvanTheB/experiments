#include "stdint.h"

int main(int argc, char const *argv[])
{
    int a = INT32_MAX;
    int b = 1;
    int r;
    return __builtin_add_overflow(a, b, &r);
}
