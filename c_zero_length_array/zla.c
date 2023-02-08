#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"

struct thing {
    int a;
    short b;
    float c[0];
};



int main(int argc, char const *argv[])
{
    printf("%x\n", sizeof(struct thing));
    printf("%x\n", offsetof(struct thing, a));
    printf("%x\n", offsetof(struct thing, b));
    printf("%x\n", offsetof(struct thing, c));

    struct thing *t;
    printf("%x\n", sizeof(*t) + sizeof(t->c[0]) * 10);
    t = malloc(sizeof(*t) + sizeof(t->c[0]) * 10);
    t->a = 1;
    t->b = 2;
    for (int i = 0; i < 10; i++) {
        t->c[i] = i * 2.;
    }

    return 0;
}
