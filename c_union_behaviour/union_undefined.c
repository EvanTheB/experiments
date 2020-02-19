union a {
    long long x;
    int y;
};

int main(int argc, char const *argv[])
{
    /* does writing to the small value overwrite the other? */
    union a b;
    b.x = 0 - 1;
    b.y = 0;
    printf("%lX\n", b.x);
    return 0;
}
