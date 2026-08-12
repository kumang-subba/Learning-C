#include <stdio.h>
#include <stdlib.h>

int main() {
  char *fname;
  char *lname;
  unsigned long n;
  printf("Enter your first name: ");
  scanf("%ms", &fname);
  printf("Enter your last name: ");
  scanf("%ms", &lname);

  printf("Hello %s %s!\n", fname, lname);

  free(fname);
  free(lname);
  return 0;
}
