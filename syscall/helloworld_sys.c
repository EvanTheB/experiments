#define _GNU_SOURCE      /* See feature_test_macros(7) */
#include <sys/syscall.h> /* For SYS_xxx definitions */
#include <unistd.h>

int main(int argc, char *argv[]) {
  char * hw = "Hello World\n";
  long res = syscall(SYS_write, 1, hw, 12);
  syscall(SYS_exit, 0);
}
