#include <stdio.h>

int duplicates(int *arr, int n);

int main() {
  int n;

  printf("Enter the size of an array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int result = duplicates(arr, n);

  if (result) {
    printf("Duplicate found");
  } else {
    printf("No duplicates found");
  }

  return 0;
}

int duplicates(int *arr, int n) {
  int *p, *q;

  for (p = arr; p < arr + n; p++) {
    for (q = p + 1; q < arr + n; q++) {
      if (*p == *q) {
        return 1;
      }
    }
  }

  return 0;
}
