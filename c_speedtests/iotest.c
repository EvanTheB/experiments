// OG from https://lemire.me/blog/2012/06/26/which-is-fastest-read-fread-ifstream-or-mmap/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "fcntl.h"
#include "unistd.h"

static unsigned doSomeComputation(unsigned * numbers, size_t size) {
    unsigned answer = 0;
    // totally arbitrary
    for(size_t k = 0; k < size; k+= 2) {
        answer += numbers[k];
    }
    for(size_t k = 1; k < size; k+= 2) {
        answer += numbers[k] * 2;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    // this many ints at once
    unsigned bufsiz;
    sscanf(argv[2], "%u", &bufsiz);

    if (0 == strcmp(argv[1], "fread"))
    {
        unsigned *buf = malloc(sizeof (unsigned) * bufsiz);
        FILE* fp = fopen(argv[3], "r");
        unsigned acc = 0;
        size_t read_count;
        while((read_count = fread(buf, sizeof(unsigned), bufsiz, fp)))
        {
            acc += doSomeComputation(buf, read_count);
        }
        printf("%u\n", acc);
    }
    else if (0 == strcmp(argv[1], "read"))
    {
        unsigned char *curbuf = malloc(sizeof (unsigned) * bufsiz);
        if (!curbuf) exit(1);
        unsigned char *const buf = curbuf;
        int fd = open(argv[3], O_RDONLY);
        unsigned acc = 0;
        ssize_t read_count;
        while((read_count = read(fd, curbuf, sizeof(unsigned) * (bufsiz - 2))) > 0)
        {

            size_t bytes = (size_t)(curbuf - buf) + read_count;
            size_t full_pairs = (bytes / sizeof(unsigned)) / 2 * 2;
            acc += doSomeComputation((unsigned *)buf, full_pairs);
            size_t extra_bytes = bytes - (full_pairs * sizeof(unsigned));

            // fprintf(stderr, "%zd %zu\n", read_count, full_pairs);
            memmove(buf, buf+full_pairs * sizeof(unsigned), extra_bytes);
            curbuf = buf + extra_bytes;
        }
        printf("%u\n", acc);
    }
}
