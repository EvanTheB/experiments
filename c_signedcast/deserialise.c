int main(int argc, char const *argv[])
{
    for (int i = 0; i < 256; ++i)
    {
        unsigned char u = i;
        signed char s = u;
        printf("%d\n", s);
        /* code */
    }
    return 0;
}

