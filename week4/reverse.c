#include <stdio.h>

void reverseArray(int arr[], int n) {
  int i, temp;

  for (i = 0; i < n / 2; i++) {
    temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i;

  reverseArray(arr, n);

  int size = sizeof(arr);
  printf("Size of array in bytes: %d\n", size);

  printf("Reversed array: \n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
