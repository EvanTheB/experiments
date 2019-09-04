#include "stdio.h"

main(int argc, char** argv) {
    char buf[1024];
    FILE* fp = fopen(argv[1], "r");
    fread(buf, 5, 1, fp);
}
