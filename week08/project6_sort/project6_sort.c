/*
 * Program to read a list of grocery items from an input file,
 * sort them alphabetically, and write the sorted list
 * to an output file.
 * Author: Felix Hoang
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_LEN 101

// --- Function Prototypes ---

void swap_str(char str1[], char str2[]);
int find_largest(char items[][MAX_LEN], int n);
void selection_sort(char items[][MAX_LEN], int n);

// --- Main Function ---

int main(int argc, char *argv[]) {
  // Check for the correct number of command-line arguments
  if (argc != 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Declare variables
  char items[MAX_ITEMS][MAX_LEN]; // 2D array to store grocery items
  int count = 0;                  // Counter for the number of items read
  FILE *in_file;                  // Pointer for the input file
  FILE *out_file;                 // Pointer for the output file

  // Open and read the input file
  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    printf("Error: Cannot open input file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Read items from file into the 2D array
  while (count < MAX_ITEMS && fscanf(in_file, "%s", items[count]) == 1) {
    count++;
  }

  // Close the input file
  fclose(in_file);

  // Call the sorting function, pass the array and the actual number of items
  selection_sort(items, count);

  // Open and write to the output file
  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    printf("Error: Cannot open output file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  // Write the sorted items to the output file, each on a new line
  for (int i = 0; i < count; i++) {
    fprintf(out_file, "%s\n", items[i]);
  }

  // Close the output file
  fclose(out_file);

  return 0;
}

// --- Function Definitions ---

/**
 * Swaps two strings using a temporary buffer.
 */
void swap_str(char str1[], char str2[]) {
  char temp[MAX_LEN];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

/**
 * Finds the index of the largest string (alphabetically).
 * This is the helper function for the selection sort.
 */
int find_largest(char items[][MAX_LEN], int n) {
  int max_idx = 0; // Assume first item is the largest initially

  // Loop from the second item (index 1) to the end (n-1)
  for (int i = 1; i < n; i++) {
    if (strcmp(items[i], items[max_idx]) > 0) {
      max_idx = i; // Update the index of the largest item
    }
  }
  return max_idx;
}

/**
 * Sorts the array of strings using recursive selection sort.
 * It finds the largest element and moves it to the end
 * of the "unsorted" portion of the array, then recurses.
 */
void selection_sort(char items[][MAX_LEN], int n) {
  // Base case: If the array (or subarray) has 1 or 0 elements,
  // it is already sorted.
  if (n <= 1) {
    return;
  }

  // Find the index of the largest element in the first 'n' items
  int max_idx = find_largest(items, n);

  // Swap the largest element with the last element (at index n-1)
  if (max_idx != n - 1) {
    swap_str(items[max_idx], items[n - 1]);
  }

  // Recursively sort the remaining (n-1) items
  selection_sort(items, n - 1);
}
