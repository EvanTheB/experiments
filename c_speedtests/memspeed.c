#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "assert.h"
#include "unistd.h"

int main(int argc, char const *argv[])
{
    unsigned long long size = strtoll(argv[1], NULL, 10);
    assert(sizeof size == sizeof (size_t));

    size = 1ULL << size;

    char* data = malloc(size);

    assert(data);

    for (long long i = 0; i < size; ++i)
    {
        data[i] = i;
    }

    unsigned char out = 0;

    for (long long i = 0; i < 1024LL*1024LL*1024LL; ++i)
    {
        out ^= data[((unsigned long)random()) & (size - 1)];
    }

    printf("%d\n", out);
}
