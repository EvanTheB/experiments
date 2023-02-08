int main(int argc, char const *argv[])
{
    unsigned A = 3;
    A += 0xFFFFFFFF;

    printf("%X\n", A);
    return 0;
}
