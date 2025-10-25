#include <stdio.h>
#include <stdlib.h>

void change_type(int argc, char *argv[], int *arr);
void swap(int *a, int *b);
int find_largest(int arr[], int n);
void selection_sort(int arr[], int n);
void print_array(int arr[], int n);

int main(int argc, char *argv[]) {
  int arr[argc - 1];

  change_type(argc, argv, arr);
  selection_sort(arr, argc - 1);

  print_array(arr, argc - 1);

  return 0;
}

// Change the command line arguments from string to int
// and record it onto the new array
void change_type(int argc, char *argv[], int *arr) {
  for (int i = 1; i < argc; i++) {
    *(arr++) = atoi(argv[i]);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// find the largest element in the unsorted array
// until index n of arr
int find_largest(int arr[], int n) {
  int max_idx = 0;

  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[max_idx]) {
      max_idx = i;
    }
  }

  return max_idx;
}

// Perform selection sort on the arr,
// recursion from the end to the begin of the arr
void selection_sort(int arr[], int n) {
  if (n == 1)
    return;

  int max_idx = find_largest(arr, n);
  if (max_idx < n - 1) {
    // swap the largest value to the end of the array
    swap(&arr[max_idx], &arr[n - 1]);
  }
  selection_sort(arr, n - 1);
}

void print_array(int arr[], int n) {
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
