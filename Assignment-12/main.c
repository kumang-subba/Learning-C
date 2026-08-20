#include <bits/types/timer_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOWER 1
#define UPPER 2

int
main()
{
    int             fc, i;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand(ts.tv_sec + ts.tv_nsec);

    printf("How many times would you like to flip the coin? ");
    scanf("%d", &fc);

    int fca[UPPER];

    memset(fca, 0, UPPER);

    for (i = 0; i < fc; i++) {
        fca[((rand() % UPPER) + LOWER) - 1]++;
    }

    printf(" After flipping the coin %d times, the results were\n", fc);
    printf("%d heads\n%d tails\n", fca[0], fca[1]);

    return 0;
}
