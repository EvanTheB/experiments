#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define CLIENT_PATH "./socket_c"
#define SERVER_PATH "./socket_s"

int main() {
    unlink(CLIENT_PATH);

    int s = socket(PF_UNIX, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("client");
        exit(1);
    }

    struct sockaddr_un addr = {.sun_family = AF_UNIX, .sun_path = SERVER_PATH};
    if (connect(s, (struct sockaddr *)&addr, sizeof addr) < 0) {
        perror("client");
        exit(1);
    }

    char buf[1024];
    int bytes_read;
    while ((bytes_read = read(s, buf, 1024)) > 0) {
        printf("client read: %*s", bytes_read, buf);
    }
}
