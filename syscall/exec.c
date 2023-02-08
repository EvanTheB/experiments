#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    execve("/bin/echo", argv, envp);
    return 0;
}
