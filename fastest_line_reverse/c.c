#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, stdin)) != -1) {
         fwrite(line, nread - TRIM - 1, 1, stdout);
         printf("\n");
    }
}


