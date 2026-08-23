#include <stdio.h>
#include <stdlib.h>
int
main()
{
    char *c = malloc(sizeof(c) * 64);
    if (c == NULL) {
        perror("Malloc failed");
        return 1;
    }
    printf("Memory was successfully allocated.\n");
    return 0;
}
