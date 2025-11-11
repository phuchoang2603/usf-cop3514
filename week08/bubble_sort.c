#include <stdbool.h>
#include <stdio.h>

void bubbleSort(int *arr, int n);

int main() {
  int n = 5;
  int arr[5] = {6, 3, 6, 2, 4};

  bubbleSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

void bubbleSort(int *arr, int n) {
  int *p, *q;
  bool swapped = false;

  for (p = arr + n - 1; p > arr; p--) {
    swapped = false;

    for (q = arr; q < p; q++) {
      if (*q > *(q + 1)) {
        int temp = *q;
        *q = *(q + 1);
        *(q + 1) = temp;
        swapped = true;
      }
    }

    if (swapped == false) {
      break;
    }
  }
}
