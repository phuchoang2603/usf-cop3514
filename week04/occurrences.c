#include <stdio.h>

int count(int arr[], int n, int target) {
  int i, count = 0;

  for (i = 0; i < n; i++) {
    if (arr[i] == target) {
      count++;
    }
  }

  return count;
}

int main() {
  int arr[] = {1, 3, 2, 3, 4, 3, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  int target = 2;
  int result = count(arr, n, target);

  printf("Number of occurrences of %d: %d\n", target, result);

  return 0;
}
