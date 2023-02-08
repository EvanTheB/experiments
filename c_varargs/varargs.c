int main(int argc, char const *argv[])
{
    printf("%x %x\n", (unsigned char)-128, (unsigned char)-127);
    printf("%hhx %hhx\n", -128, -127);
    printf("%d\n", (signed char)0xFF);
    return 0;
}
