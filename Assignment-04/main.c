#include <stdio.h>

#define PIE 3.14

int
main()
{
    double radius;
    printf("Enter the radius of your circle: ");
    scanf("%lf", &radius);
    if (radius <= 0) {
        fprintf(stderr, "Radius cannot be zero or negative");
        return 1;
    }
    printf(" The area of your circle is %lf\n", PIE * radius * radius);

    return 0;
}
