#include <stdio.h>

void get_input(int array[], int size);
void multi_vec(int v1[], int v2[], int v3[], int n);
void print_output(int array[], int size);

int main() {
  int size;
  printf("Enter length of the vectors: ");
  scanf("%d", &size);

  int a[size], b[size], c[size];

  get_input(a, size);
  get_input(b, size);

  multi_vec(a, b, c, size);

  print_output(c, size);

  return 0;
}

void get_input(int array[], int size) {
  printf("Enter %d value of the vector: ", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void print_output(int array[], int size) {
  printf("Here's the result: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}

void multi_vec(int v1[], int v2[], int v3[], int n) {
  int *p1 = v1;
  int *p2 = v2;
  int *p3 = v3;

  for (; p1 < &v1[n]; p1++, p2++, p3++) {
    *p3 = *p1 * *p2;
  }
}
