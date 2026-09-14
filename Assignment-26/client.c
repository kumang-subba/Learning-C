#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/epoll.h>

#include <netinet/in.h>

#define BUF_SIZE 4096

int main(void)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        printf("socket() failed.\n");
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3000);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (connect(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        printf("connect() failed.\n");
        close(fd);
        return 1;
    }

    int epfd = epoll_create(1);
    if (epfd < 0) {
        printf("epoll_create() failed.\n");
        close(fd);
        return 1;
    }

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = 0;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &ev) < 0) {
        printf("epoll_ctl() stdin failed.\n");
        return 1;
    }

    ev.events = EPOLLIN;
    ev.data.fd = fd;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        printf("epoll_ctl() socket failed.\n");
        return 1;
    }

    struct epoll_event events[2];
    char               buf[BUF_SIZE];

    for (;;) {
        int nrd = epoll_wait(epfd, events, 2, -1);
        if (nrd < 0) {
            if (errno == EINTR)
                continue;
            printf("epoll_wait() failed.\n");
            break;
        }

        for (int i = 0; i < nrd; i++) {
            if (events[i].events & EPOLLIN) {
                ssize_t rv = read(events[i].data.fd, buf, sizeof(buf));
                if (rv < 0) {
                    if (errno == EAGAIN) {
                        continue;
                    }
                    printf("read() failed. fd: %d.\n", events[i].data.fd);
                }
                if (events[i].data.fd != 0) {
                    printf("%s", buf);
                } else {
                    ssize_t n = 0;
                    while (n < rv) {
                        ssize_t wv = write(fd, buf + n, rv - n);
                        if (wv < 0) {
                            if (errno == EINTR) {
                                continue;
                            }
                            printf("write() failed\n");
                            goto cleanup;
                        }
                        n += wv;
                    }
                }
            } else if (events[i].events & EPOLLERR) {
                goto cleanup;
            }
        }
    }

cleanup:
    close(epfd);
    close(fd);

    return 0;
}
