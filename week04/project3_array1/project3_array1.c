/*
 * This program check the array input is valid
 * Author: Felix Hoang
 */

#include <stdio.h>

int main() {
  int valid = 1;

  printf("Enter the length of the input array: ");
  int len;
  scanf("%d", &len);

  printf("Enter the array elements: ");
  int arr[len];
  for (int i = 0; i < len; i++) {
    scanf("%d", &arr[i]);
  }

  // Starting from 2 to n
  for (int i = 1; i < len; i++) {
    // Check if a1 > a2 > ... > an or an is divisible by an-1
    if ((arr[i - 1] > arr[i]) || (arr[i] % arr[i - 1] == 0))
      valid = 0;
  }

  (valid == 1) ? printf("Output: yes") : printf("Output: no");

  return 0;
}
