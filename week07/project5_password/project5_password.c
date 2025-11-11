/*
 * This program validates a password provided as a command-line
 * argument. It checks if the correct number of arguments is given and
 * then validates the password based on length, and presence of
 * uppercase, lowercase, and digit characters.
 *
 * author: Felix Hoang
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Check if the number of arguments is exactly 2
  if (argc != 2) {
    printf("Invalid number of arguments\n");
    return 1;
  }

  char *password = argv[1];
  int len = strlen(password);

  // Initialize flags for password criteria
  int has_upper = 0;
  int has_lower = 0;
  int has_digit = 0;
  int has_no_special = 1; // valid until found
  int has_valid_length = 0;

  // Check for valid length (assuming 8 or more characters)
  if (len >= 8) {
    has_valid_length = 1;
  }

  // Iterate through password to check types
  for (int i = 0; i < len; i++) {
    char ch = password[i];
    if (isupper(ch)) {
      has_upper = 1;
    } else if (islower(ch)) {
      has_lower = 1;
    } else if (isdigit(ch)) {
      has_digit = 1;
    } else {
      has_no_special = 0;
    }
  }

  if (has_valid_length && has_upper && has_lower && has_digit &&
      has_no_special) {
    printf("Valid\n");
  } else {
    printf("Invalid\n");
  }

  return 0;
}
