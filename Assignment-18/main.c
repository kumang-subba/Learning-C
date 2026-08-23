#include <stdio.h>

void
hello(void)
{
    // not null terminated
    char array1[] = { 72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33 };
    // null terminated
    char array2[] = { 72, 101, 108, 108, 111, 44, 32,
                      87, 111, 114, 108, 100, 33, '\0' };

    // printf will iterate until it finds the null terminated byte `\0` or value 0.
    printf("array 1: %s\n", array1);
    printf("array 2: %s\n", array2);
}

int
main(void)
{
    hello();
}
