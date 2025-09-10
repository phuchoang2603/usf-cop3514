// What does the following code segment output?

#include <stdio.h>

int main() {

  int i, j, count = 0;

  for (i = 1; i <= 3; i++) {
    for (j = 0; j < 4; j++) {
      // i = 1, j = 1 -> count = 1
      // i = 1, j = 3 -> count = 1 + 3
      // i = 3, j = 1 -> count = 4 + 1
      // i = 3, j = 3 -> count = 5 + 3
      if ((i * j) % 2 == 0) {
        continue;
      }

      count += j;
    }
  }

  printf("%d\n", count);

  return 0;
}
