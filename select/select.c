/* According to POSIX.1-2001, POSIX.1-2008 */
#include <sys/select.h>

/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main(void) {
  fd_set rfds;
  struct timeval tv;
  int retval;

  /* Watch stdin (fd 0) to see when it has input. */

  printf("FD_SETSIZE %d\n", FD_SETSIZE);
  printf("longbits %zd\n",  8 * sizeof (long));
  printf("fd_set %zd\n", 8 * sizeof (fd_set));

  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  /* Wait up to five seconds. */

  tv.tv_sec = 5;
  tv.tv_usec = 0;

  retval = select(1, &rfds, NULL, NULL, &tv);
  /* Don't rely on the value of tv now! */

  if (retval == -1)
    perror("select()");
  else if (retval){
    printf("Data is available now.\n");
    printf("FD_ISSET: %d", FD_ISSET(0, &rfds));
  }
  /* FD_ISSET(0, &rfds) will be true. */
  else
    printf("No data within five seconds.\n");


}

// void FD_CLR(int fd, fd_set *set);
// int  FD_ISSET(int fd, fd_set *set);
// void FD_SET(int fd, fd_set *set);
// void FD_ZERO(fd_set *set);
