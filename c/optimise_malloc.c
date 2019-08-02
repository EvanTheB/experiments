int main(int argc, char const *argv[])
{
    int *x;
    x = malloc(sizeof(int));

    int y = 0;
    for (*x = 0; *x < 100; ++(*x))
    {
        y += *x;
    }
    printf("%d %d\n", y, *x);

    return 0;
}
