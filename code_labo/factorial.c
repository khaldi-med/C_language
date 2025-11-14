#include <stdio.h>
long int factorial(int N) {
  if (N < 2) {
    return 1; // 0!==1, 1!==1
  }
  return N * factorial(N - 1);
}

int main(void) {
  printf("%lu\n", factorial(8));
  return (0);
}
