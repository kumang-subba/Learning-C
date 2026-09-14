#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (fd < 0) {
        printf("The open operation failed...\n");
        return -1;
    }
    printf("The open operation succeeded!\n");
    return 0;
}
