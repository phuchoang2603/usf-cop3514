#include <stdio.h>

int *bigger(int *a, int *b);

int main() {
  int a = 10, b = 15;
  int *p = bigger(&a, &b);
  printf("Bigger number is %d", *p);
}

int *bigger(int *a, int *b) {
  if (*a > *b) {
    return a;
  } else {
    return b;
  }
}
