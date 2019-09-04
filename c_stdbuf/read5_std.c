#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


main(int argc, char** argv) {
    char buf[1024];
    read(STDIN_FILENO, buf, 5);
}
