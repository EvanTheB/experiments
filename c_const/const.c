int newmain(int argc, char const *argv[])
{

}

int main(int argc, char const *argv[])
{
    /* you are not allowed to implicit constify cast double dereference types */
    char *args = { "test" };
    newmain(1, &args );

    char ** starargs = &args;
    newmain(1, starargs );

    return 0;
}
