#include <stdio.h>
#define PLAYER_COUNT 5

typedef struct {
  int points;
  int games;
} Stats;

int main() {
  Stats p_stats[PLAYER_COUNT];
  int i;
  for (i = 0; i < PLAYER_COUNT; i++) {
    printf("Enter Player %d's point total: ", i + 1);
    scanf("%d", &p_stats[i].points);
    printf("Enter Player %d's game total: ", i + 1);
    scanf("%d", &p_stats[i].games);
  }

  for (i = 0; i < PLAYER_COUNT; i++) {
    printf("Player %d's scoring average was %.2f ppg.\n", i + 1,
           (double)p_stats[i].points / p_stats[i].games);
  }
  return 0;
}
