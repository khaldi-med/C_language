#include <stdio.h>
int main(void) {
  char *arr[] = {"hello", "from", "fez", NULL};
  int i = 0;
  while (arr[i]) {
    printf("%s\n", arr[i]);
    i++;
  }
  return (0);
}
