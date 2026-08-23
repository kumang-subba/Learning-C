#include <stdio.h>
int
main()
{
    int  num = 1086;

    int *ptr = &num;
    printf("The value of our pointer is: %d\n", *ptr);
    return 0;
}
