#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int  filedescriptor;
    char data[] = "Writing test data to the file";

    filedescriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (filedescriptor < 0) {
        printf("The open operation failed...\n");
        return -1;
    } else {
        printf("The open operation succeeded!\n");
    }

    int wv;
    wv = write(filedescriptor, data, sizeof(data));
    if (wv <= 0) {
        printf("The write operation failed...\n");
        return -1;
    }
    printf("The write operation succeeded!\n");
    return 0;
}
