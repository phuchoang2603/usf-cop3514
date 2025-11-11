#include <stdio.h>

int main() {
  int i;

  // i = 0;

  // while (i < 5) {
  //   printf("%d\n", i);
  //   i++;
  // }

  // do {
  //   pfintf("%d\n", i);
  //   i++;
  // } while (i < 5);

  for (i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      continue;
    }

    printf("%d\n", i);
  }

  return 0;
}
