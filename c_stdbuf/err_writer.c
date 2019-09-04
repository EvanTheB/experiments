#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


main(int argc, char** argv) {
    int len = strlen(argv[1]);
    argv[1][len] = '\n';
    while (1) {
        write(STDERR_FILENO, argv[1], len + 1);
    }
}
