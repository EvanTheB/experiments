#define _GNU_SOURCE
#include <signal.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
  pid_t tid;

  tid = syscall(SYS_gettid);
  printf("%d\n", tid);
  syscall(SYS_tgkill, getpid(), tid, SIGHUP);
}
