#include <stdio.h>
#include <stdlib.h>

void change_type(int argc, char *argv[], int *arr);
void swap(int *a, int *b);
void selection_sort(int arr[], int n);

int main(int argc, char *argv[]) {
  int arr[argc - 1];

  change_type(argc, argv, arr);
  selection_sort(arr, argc - 1);

  for (int i = 0; i < argc - 1; i++) {
    printf("%d ", arr[i]);
  }

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

// Perform selection sort on the arr
void selection_sort(int arr[], int n) {
  int i, j, min_idx;

  // one by one move boundary of unsorted array
  for (i = 0; i < n - 1; i++) {
    // find the minimum element in the unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // swap the found minimum element with the first element
    // of the unsorted array
    swap(&arr[min_idx], &arr[i]);
  }
}
