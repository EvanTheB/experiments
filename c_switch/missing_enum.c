enum x
{
    a_1,
    a_2,
    a_3,
    a_4,
};

int main(int argc, char const *argv[])
{
    enum x y = argc;
    switch(y)
    {
        case a_1:
        case a_2:// we do get a warning on missing enum from switch
        case 3: // but not for a misnamed value
        case 10:// and for a value not from the enum
            break;
    }
    return 0;
}
