#define a_1 1
#define a_2 2
#define a_3 3

int main(int argc, char const *argv[])
{
    switch(argc)
    {
        // no warning for defines missing from case
        case a_1:
        case a_2:
            break;
    }
    return 0;
}
