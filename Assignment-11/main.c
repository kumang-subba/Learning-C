#include <stdio.h>
#include <string.h>

#define MAX_NUM_SCORES 8

int main() {
  int i, scores[MAX_NUM_SCORES], n, sum = 0;
  char buf[8];
  for (i = 0; i < MAX_NUM_SCORES; i++) {
    printf("Enter a test score:");
    scanf("%d", &n);
    scores[i] = n;
    sum += n;
  retry:
    printf(" Would you like to continue? Y/N ");
    scanf("%s", buf);
    if (strcmp(buf, "Y") == 0) {
      continue;
    } else if (strcmp(buf, "N") == 0) {
      break;
    } else {
      printf("Invalid input.\n");
      goto retry;
    }
  }
  printf("%.2f is the average.\n", (double)sum / (i + 1));
  return 0;
}
