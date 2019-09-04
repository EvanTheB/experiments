#include "stdio.h"

main(int argc, char** argv) {
    char buf[1024];
    fread(buf, 5, 1, stdin);
}
