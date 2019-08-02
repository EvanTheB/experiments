#define _GNU_SOURCE

#include "stdio.h"
#include <unistd.h>

extern char** environ;

int main(int argc, char *argv[], char *envp[])
{
    char *a[] = {"abc", NULL};
    char *e[] = {"xyz", NULL};
    execvpe("/home/evaben/code/test/envp", a, e);
    perror("");
    return -1;
}
