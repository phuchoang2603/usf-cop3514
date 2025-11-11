#include <stdio.h>

void add_vector(double v1[], double v2[], double result[], int n) {
  for (int i = 0; i < n; i++) {
    result[i] = v1[i] + v2[i];
  }
}

void scalar_multiply(double v[], double scalar, double result[], int n) {
  for (int i = 0; i < n; i++) {
    result[i] = v[i] * scalar;
  }
}

double dot_product(double v1[], double v2[], int n) {
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    result += v1[i] * v2[i];
  }
  return result;
}

int main() {
  double vec1[] = {1, 2, 3};
  double vec2[] = {4, -1, 2};
  int n = 3;
  int choice;
  double result[n];
  double scalar;

  printf("Menu: \n1. Add vectors\n2. Scalar Multiplication\n3. Dot Product\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    add_vector(vec1, vec2, result, n);
    printf("Resultant vector: ");
    for (int i = 0; i < n; i++) {
      printf("%.2f ", result[i]);
    }

  case 2:
    printf("Enter scalar value: ");
    scanf("%lf", &scalar);
    scalar_multiply(vec1, scalar, result, n);
    printf("Resultant vector: ");
    for (int i = 0; i < n; i++) {
      printf("%.2f ", result[i]);
    }
    break;

  case 3:
    printf("Dot product: %.2f\n", dot_product(vec1, vec2, n));
    break;

  default:
    printf("Invalid choice\n");
    break;
  }

  return 0;
}
