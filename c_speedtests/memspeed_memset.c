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

    memset(data, 0, size);

    unsigned char out = 0;
    out ^= data[((unsigned long long)random()) & (size - 1)];

   // for (long long i = 0; i < 1024LL*1024LL*1024LL; ++i)
    //{
     //   out ^= data[((unsigned long)random()) & (size - 1)];
    //}

    printf("%d\n", out);
}
