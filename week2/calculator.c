#include <stdio.h>

int main() {
  char op;
  float a, b;

  while (1) {
    printf("Enter an operation or q to quit: ");
    scanf(
        " %c",
        &op); // add leading space to skip newline character on the next output

    if (op == 'q') {
      break;
    }

    printf("Enter two numbers: ");
    scanf(" %f %f", &a, &b);

    switch (op) {
    case '+':
      printf("Result = %.2f\n", a + b);
      break;
    case '-':
      printf("Result = %.2f\n", a - b);
      break;
    case '*':
      printf("Result = %.2f\n", a * b);
      break;
    case '/':
      if (b == 0) {
        printf("Error quotient\n");
      } else {
        printf("Result = %.2f\n", a / b);
      }
      break;
    default:
      printf("Invalid operation");
      break;
    }
  }

  return 0;
}
