/* This program check_attendace of students who be there more than 40 minutes */

#include <stdio.h>

#define STUDENTS 4
#define DAYS 3

int check_attendace(int *minutes, int days, char *result);

int main() {
  char names[STUDENTS][20] = {"Alice", "Bob", "Carlos", "Dana"};

  int minutes[STUDENTS][DAYS] = {
      {62, 57, 28}, // Alice
      {38, 15, 70}, // Bob
      {45, 0, 49},  // Carlos
      {40, 39, 0}   // Dana
  };

  char results[DAYS];

  for (int i = 0; i < STUDENTS; i++) {
    int present_count = check_attendace(minutes[i], DAYS, results);
    printf("%-10s", names[i]);
    for (int d = 0; d < DAYS; d++) {
      printf(" %c ", results[d]);
    }
    printf(" | %d \n", present_count);
  }

  return 0;
}

int check_attendace(int *minutes, int days, char *result) {
  int present_count = 0;

  for (int d = 0; d < days; d++) {
    if (*(minutes + d) > 40) {
      result[d] = 'P';
      present_count++;
    } else {
      result[d] = 'A';
    }
  }

  return present_count;
}
