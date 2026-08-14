#include <stdio.h>
int
main()
{
    int input;
    printf("Enter a number between 1 and 500: ");
    scanf("%d", &input);

    if (input <= 0) {
        goto not_in_range;
    }
    for (int i = 100; i <= 500; i += 100) {
        if (input <= i) {
            printf("Your number is between %d and %d!", i - 99, i);
            return 0;
        }
    }

not_in_range:
    printf("Your number was not in any of our ranges.");
    return 0;
}
