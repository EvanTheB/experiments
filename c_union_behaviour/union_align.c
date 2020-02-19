union a {
    char x[5];
};

union b {
    float f;
    char x[5];
};

union c {
    int f;
    char x[5];
};

union d {
    double f;
    char x[9];
};

int main(int argc, char const *argv[])
{
    /* how does alignment work? */
    printf("%zu\n", sizeof(union a));
    printf("%zu %zu\n", sizeof (float), sizeof(union b));
    union b b;
    printf("%p %p %p\n", &b, &(b.f), &(b.x[0]));

    printf("%zu\n", sizeof(union c));
    printf("%zu\n", sizeof(union d));
    return 0;
}
