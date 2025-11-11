#include <stdio.h>

void greet() { printf("Hello, World!\n"); }

int square(int x) { return x * x; }

int sum_array(int arr[], int n) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += arr[i];
  }
  return total;
}

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
  // n * n-1 * n-2 * ... * 1
}

int main(int argc, char const *argv[]) {
  greet();

  // int num = 5;
  // int result = square(num);
  //
  // printf("The square of %d is %d\n", num, result);

  // int nums[5] = {1, 2, 3, 4, 5};
  //
  // printf("The sum of the array is %d\n", sum_array(nums, 5));

  printf("The factorial of %d is %d\n", 5, factorial(5));

  return 0;
}
