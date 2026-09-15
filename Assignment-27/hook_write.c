#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    ssize_t (*real_write)(int fd, const void *buf, size_t count);
    real_write = dlsym(RTLD_NEXT, "write");
    int n;
    if (strcmp(buf, "Hello world!\n") == 0) {
        n = real_write(fd, "Goodbye, cruel world!\n",
                       sizeof("Goodbye, cruel world!\n"));
    } else {
        n = real_write(fd, buf, count);
    }
    return n;
}
