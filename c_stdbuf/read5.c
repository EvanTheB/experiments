#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


main(int argc, char** argv) {
    char buf[1024];
    int fd = open(argv[1], 0);
    read(fd, buf, 5);
}
