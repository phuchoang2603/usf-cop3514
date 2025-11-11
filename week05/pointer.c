#include <stdio.h>

int main() {
  // * return the value of pointer, & return the address
  // Assignment 1
  int *p, *q;
  int i = 4, j = 6;

  p = &i;
  q = &j;

  printf("%p %d\n", p, i);
  printf("%p %p\n", &i, &*p);

  *p = 32;
  printf("%d %p\n", *&i, p);

  p = q;
  printf("%d %d %d %d\n", i, j, *p, *q);

  // Assignment 2
  int arr[4] = {5, 8, 2, 9};

  int k, *r;
  for (k = 0; k < 4; k++) {
    r = &arr[k];
    printf("%d %p\n", *r, r);
  }

  return 0;
}
