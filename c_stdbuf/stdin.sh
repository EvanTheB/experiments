strace -e read python3 -c '
import sys;
open(sys.argv[1]).read(5)' characters


