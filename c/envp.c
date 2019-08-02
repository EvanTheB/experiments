#include "stdio.h"
int main(int argc, char *argv[], char *envp[])
{
    printf("%p %p\n", argv, envp);
    while(*argv)
    {
        printf("%s\n", *argv);
        argv++;
    }
    while(*envp)
    {
        printf("%s\n", *envp);
        envp++;
    }
}
