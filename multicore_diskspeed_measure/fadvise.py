import os
import sys

for f in sys.argv[1:]:
	os.posix_fadvise(os.open(f, os.O_RDONLY), 0, 999999999999, os.POSIX_FADV_DONTNEED)
