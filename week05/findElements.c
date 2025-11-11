#include <stdio.h>

int find_elements(int a[], int n1, int b[], int n2, int c[]) {
  int count = 0;
  int i, j;

  for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
      if (b[j] == a[i]) {
        c[count] = b[j];
        count++;
        break;
      }
    }
  }

  return count;
}

int main() {
  int a[] = {1, 2, 3};
  int b[] = {3, 2, 6, 7};

  int n1 = sizeof(a) / sizeof(a[0]);
  int n2 = sizeof(b) / sizeof(b[0]);

  int sizeofc = (n2 < n1) ? n1 : n2;
  int c[sizeofc];

  printf("%d", find_elements(a, n1, b, n2, c));
}
