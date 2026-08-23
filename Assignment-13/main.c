#include <stdio.h>

#define GAMES_N   4
#define PLAYERS_C 5

int
main()
{
    int i, j, scores[GAMES_N][PLAYERS_C], sum_a[PLAYERS_C] = { 0 }, highest = 0;

    for (i = 0; i < GAMES_N; i++) {
        printf("Game #%d\n", i + 1);
        for (j = 0; j < PLAYERS_C; j++) {
            printf(" Enter scoring total for Player #%d: ", j + 1);
            scanf("%d", &scores[i][j]);
            sum_a[j] += scores[i][j];
            if (sum_a[highest] < sum_a[j]) {
                highest = j;
            }
        }
    }
    printf(" Player #%d had the highest scoring average at %.2f points per game.\n",
           highest + 1, sum_a[highest] / (double) GAMES_N);

    return 0;
}
