#include "stdio.h"

main() {
    char * buf = "abc\nabc\n";
    fwrite(buf, 1, strlen(buf), stdout);
}
