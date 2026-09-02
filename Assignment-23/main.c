#include <stdio.h>
int main()
{
    struct example {
        int integer;
    };

    struct example *ptr;

    struct example  test;

    ptr = &test;

    test.integer = 5;
    printf("%d\n", test.integer);

    (*ptr).integer = 6;
    printf("%d\n", test.integer);

    ptr->integer = 7;
    printf("%d\n", test.integer);

    return 0;
}
