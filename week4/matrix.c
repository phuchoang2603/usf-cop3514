#include <stdio.h>

int main(int argc, char const *argv[]) {
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int rows = 3;
  int cols = 3;

  printf("The matrix is:\n");

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      printf("%d ", matrix[row][col]);
    }
    printf("\n");
  }

  return 0;
}
