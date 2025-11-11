#include <stdio.h>
#include <string.h>

// Constants based on requirements
#define MAX_STUDENTS 1000
#define MAX_NAME_LEN 100
#define OUTPUT_FILENAME "result.csv"

// Student structure definition
struct student {
  char firstName[MAX_NAME_LEN];
  char lastName[MAX_NAME_LEN];
  int points;
  int level; // Assigned competition level (1, 2, or 3)
};

/**
 * Assigns a competition level to each student based on their points.
 * Level 1: 0 to 50 points
 * Level 2: 51 to 95 points
 * Level 3: 96 points or more
 */
void assign_level(struct student list[], int n) {
  for (int i = 0; i < n; i++) {
    int p = list[i].points;

    if (p >= 0 && p <= 50) {
      list[i].level = 1;
    } else if (p >= 51 && p <= 95) {
      list[i].level = 2;
    } else if (p >= 96) {
      list[i].level = 3;
    } else {
      // Handle negative points case (assign level 0 or handle error)
      list[i].level = 0;
    }
  }
}

int main() {
  struct student studentList[MAX_STUDENTS];
  char inputFileName[MAX_NAME_LEN];
  int studentCount = 0;
  FILE *inputFile, *outputFile;

  printf("Enter file name: ");
  if (scanf("%s", inputFileName) != 1) {
    fprintf(stderr, "Error reading file name.\n");
    return 1;
  }

  inputFile = fopen(inputFileName, "r");
  if (inputFile == NULL) {
    fprintf(
        stderr,
        "Error: Could not open input file '%s'. Please check the file path.\n",
        inputFileName);
    return 1;
  }

  while (studentCount < MAX_STUDENTS &&
         fscanf(inputFile, "%[^,], %[^,], %d\n",
                studentList[studentCount].firstName,
                studentList[studentCount].lastName,
                &studentList[studentCount].points) == 3) {
    studentCount++;
  }

  if (ferror(inputFile)) {
    fprintf(stderr, "Error occurred while reading from the input file.\n");
  }

  fclose(inputFile);

  assign_level(studentList, studentCount);

  outputFile = fopen(OUTPUT_FILENAME, "w");
  if (outputFile == NULL) {
    fprintf(stderr, "Error: Could not open output file '%s' for writing.\n",
            OUTPUT_FILENAME);
    return 1;
  }

  for (int i = 0; i < studentCount; i++) {
    fprintf(outputFile, "%s,%s,%d,%d\n", studentList[i].firstName,
            studentList[i].lastName, studentList[i].points,
            studentList[i].level);
  }

  fclose(outputFile);

  printf("Output file: %s\n", OUTPUT_FILENAME);

  return 0;
}
