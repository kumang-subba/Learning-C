#include <stdio.h>
int
main()
{
    int num, den;
    printf("Enter a numerator: ");
    scanf("%d", &num);
    printf("Enter a denominator: ");
    scanf("%d", &den);

    if (den == 0) {
        fprintf(stderr, "Denominator cannot be zero\n");
        return 1;
    }

    printf("There is %sa remainder!\n", num % den ? "" : "NOT ");

    return 0;
}
