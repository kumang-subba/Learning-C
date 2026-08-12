#include <stdio.h>

int
main()
{
    int sec, hrs, mins;
    printf("Enter the amount of seconds: ");
    scanf("%d", &sec);
    printf("%d seconds is equal to ", sec);
    for (hrs = 0, mins = 0; sec >= 60; sec -= 60) {
        mins++;
        if (mins >= 60) {
            hrs++;
            mins = 0;
        }
    };
    printf("%d hours, %d minutes, and %d seconds.\n", hrs, mins, sec);
    return 0;
}
