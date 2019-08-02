#include "stdio.h"
#include "stdlib.h"

static double compute(double t, const double *restrict a, const double *restrict b, double *restrict c, size_t l)
{
    for (size_t i = 0; i < l; ++i)
    {
        c[i] = a[i] * b[i];
    }
    double acc = 0;
    for (size_t i = 0; i < l; ++i)
    {
        acc += c[i] * t;
        t *= t;
    }
    return acc;
}

int main(int argc, char const *argv[])
{
    unsigned bufsiz;
    sscanf(argv[1], "%u", &bufsiz);
    printf("%u\n", bufsiz);

    double *a = malloc(sizeof (double) * bufsiz);
    double *b = malloc(sizeof (double) * bufsiz);
    double *c = malloc(sizeof (double) * bufsiz);
    FILE* fp = fopen(argv[2], "r");

    size_t read_count;
    read_count = fread(a, sizeof(double), bufsiz, fp);
    read_count = fread(b, sizeof(double), bufsiz, fp);
    // read_count = fread(c, sizeof(unsigned), bufsiz, fp);

    double ans = compute(0.999999, a,b,c,bufsiz);

    printf("%f\n", ans);
    return 0;
}
