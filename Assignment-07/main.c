#include <stdio.h>
#include <math.h>

int
main()
{
    int    A, B, C;
    double root;
    printf("Enter the value of variable 'A': ");
    scanf("%d", &A);
    printf("Enter the value of variable 'B': ");
    scanf("%d", &B);
    printf("Enter the value of variable 'C': ");
    scanf("%d", &C);

    root = sqrt((B * B) - (4 * A * C));

    printf("The solution using the '+' operator is: %lf\n",
           (-B + root) / (2 * A));
    printf("The solution using the '-' operator is: %lf\n",
           (-B - root) / (2 * A));

    return 0;
}
