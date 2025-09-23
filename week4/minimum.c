#include <stdio.h>

int find_minimum(int arr[], int n) {
  int min = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  return min;
}

int main() {
  int arr[] = {5, 3, 8, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  int min = find_minimum(arr, n);
  printf("The minimum value in the array is: %d\n", min);

  return 0;
}
