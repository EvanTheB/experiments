#include "stdio.h"

main(int argc, char** argv) {
    int len = strlen(argv[1]);
    argv[1][len] = '\n';
    while (1) {
        fwrite(argv[1], 1, len + 1, stderr);
    }
}
