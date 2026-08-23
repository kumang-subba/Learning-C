#include <stdio.h>
struct data_s {
    int   num;
    char  ch;
    float fl;
};

int
main()
{
    struct data_s d = { 50, 'W', 3.14 };

    printf("This is the int: %d, this is the char: %c, this is the float: %.2f\n",
           d.num, d.ch, d.fl);
    return 0;
}
