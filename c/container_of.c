#include "stdio.h"
#include "stddef.h"

#define container_of(ptr, type, member)                 \
({                              \
    const typeof(((type *) NULL)->member) *__mptr = (ptr);  \
    (type *) (void*)((char *) __mptr - offsetof(type, member)); \
})

#define container_of_2(ptr, type, member)                 \
({                              \
    const void *__mptr = (void*)(ptr);  \
    (type *) (__mptr - offsetof(type, member)); \
})

struct cont {
    int first;
    int second;
};

int main() 
{
    struct cont a = {0};

    int * mine = &(a.second);

    printf("%p %p", &a, container_of(mine, struct cont, second));
    printf("%p %p", &a, container_of_2(mine, struct cont, second));
}
