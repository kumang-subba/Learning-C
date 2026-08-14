#include <stdio.h>

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage %s Firstname Lastname\n", argv[0]);
        return 0;
    }
    printf("Hello");
    while (--argc) {
        printf(" %s", *(++argv));
    }
    printf("\n");

    return 0;
}
