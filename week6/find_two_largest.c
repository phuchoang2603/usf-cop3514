#include <stdio.h>
#define N 5

void find_two_largest(int a[], int n, int *max, int *second_max);

int main() {
  int i, max, second_max;
  int a[N];

  printf("Enter %d elements for the array: ", N);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  find_two_largest(a, N, &max, &second_max);
  printf("Largest: %d, Second largest: %d\n", max, second_max);

  return 0;
}

void find_two_largest(int a[], int n, int *max, int *second_max) {
  if (a[0] > a[1]) {
    *max = a[0];
    *second_max = a[1];
  } else {
    *max = a[1];
    *second_max = a[0];
  }
  for (int i = 2; i < n; i++) {
    if (a[i] > *max) {
      *second_max = *max;
      *max = a[i];
    } else if (a[i] > *second_max) {
      *second_max = a[i];
    } else {
      continue;
    }
  }
}
