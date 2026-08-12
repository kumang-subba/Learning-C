#include <stdio.h>
int main() {
  int i = 5;
  char *h = "Hello world!";
  float f = 3.14;
  printf("%d is an integer\n"
         "%f is a float\n"
         "%s is a char\n",
         i, f, h);
  return 0;
}
