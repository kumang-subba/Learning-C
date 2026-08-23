#include <stdio.h>

int
main()
{
    int array[10];
    printf("array start address: %p\n", array);
    printf("array first element address: %p\n", &array[0]);
    return 0;
}
