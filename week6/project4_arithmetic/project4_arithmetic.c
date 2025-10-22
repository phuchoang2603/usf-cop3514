/*
 * This program checks if a sequence of integers is an arithmetic sequence.
 * author: Felix Hoang
 */

#include <stdio.h>
#include <stdlib.h>

int is_arithmetic_sequence(int *sequence, int n);

int main(void) {
  int n;
  printf("Enter length of the sequence: ");
  scanf("%d", &n);

  int *sequence = malloc(n * sizeof(int));
  if (sequence == NULL && n > 0) {
    return 1;
  }

  printf("Enter numbers of the sequence: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &sequence[i]);
  }

  if (is_arithmetic_sequence(sequence, n)) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  free(sequence);
  return 0;
}

int is_arithmetic_sequence(int *sequence, int n) {
  // A sequence with 2 or fewer elements is always considered arithmetic.
  if (n <= 2) {
    return 1;
  }

  int common_diff = *(sequence + 1) - *sequence;

  int *current = sequence + 2;
  int *end = sequence + n;

  while (current < end) {
    if (*current - *(current - 1) != common_diff) {
      return 0;
    }
    current++;
  }

  return 1;
}
