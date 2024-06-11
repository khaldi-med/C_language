#include <stdio.h>
#include <stdlib.h>

int main() {
  int fahr, celsuis;
  int lower, upper, being;
  
  lower = 0;
  upper = 300;
  being = 20;
  
  fahr = lower;
  while (fahr <= upper) {
    celsuis = 5 * (fahr-32) / 9;
    printf("%d\t %d\n", fahr, celsuis);
    fahr += being;
  }
  return 0;
}
