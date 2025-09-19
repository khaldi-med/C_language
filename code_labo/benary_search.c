#include <stdio.h>

int benary(int *arr, int arr_size, int target) {
  int min = 0;
  int max = arr_size;
  int mid = (min + max - 1) / 2;
  int n = mid;

  while (min - max > 0) {
    if (arr[n] < target) {
      min = mid + 1;
    } else if (arr[n] > target) {
      max = mid - 1;
    } else
      break;
    mid = (min + max) / 2;
    n = mid;
  }
  return n;
}

int main(void) {
  int t = 23;
  int size = 10;
  int arr[10] = {2, 7, 9, 50, 40, 63, 23, 78, 12, 43};
  int n = benary(arr, size, t);
  printf("%d", arr[n]);
  return (0);
}
