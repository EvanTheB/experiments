int main(int argc, char const *argv[])
{
    /* what is this ternary construction? */
    int x = argc > 1 ?: 1;
    return x;
}
