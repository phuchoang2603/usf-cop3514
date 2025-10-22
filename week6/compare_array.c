#include <stdio.h>
#define N 5

int compare_array(int a[], int n, int value);

int main() {
  int count;
  int a[N];

  printf("Enter %d elements for the array: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  count = compare_array(a, N, 25);
  printf("Elements greater than 25 is: %d\n", count);

  return 0;
}

int compare_array(int a[], int n, int value) {
  int *p;
  int count = 0;

  for (p = &a[0]; p < &a[N]; p++) {
    if (*p > value) {
      count += 1;
    }
  }

  return count;
}
