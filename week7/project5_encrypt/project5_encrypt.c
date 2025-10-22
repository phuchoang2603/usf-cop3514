/*
 * This program encrypts a message using an 8-digit date as a repeating key.
 * author: Felix Hoang
 */

#include <ctype.h>
#include <stdio.h>

#define MAX_MESSAGE_LEN 1001
#define DATE_KEY_LEN 8

// Function Prototypes
int read_line(char *str, int n);
void encrypt(char *message, char *encrypted_message, int *date, int n);

int main(void) {
  char message[MAX_MESSAGE_LEN];
  char encrypted_message[MAX_MESSAGE_LEN];
  int date_digits[DATE_KEY_LEN];

  printf("Enter the message: ");
  read_line(message, MAX_MESSAGE_LEN);

  printf("Enter date in the format of 8 digits: ");
  for (int i = 0; i < DATE_KEY_LEN; i++) {
    scanf("%1d", &date_digits[i]);
  }

  encrypt(message, encrypted_message, date_digits, DATE_KEY_LEN);

  printf("%s\n", encrypted_message);

  return 0;
}

// Reads a line of input using pointer arithmetic.
int read_line(char *str, int n) {
  int ch;
  char *p = str;
  char *end = str + n - 1;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (p < end) {
      *p++ = ch;
    }
  }
  *p = '\0';
  return p - str;
}

// Encrypts the message using the date key with pointer arithmetic.
void encrypt(char *message, char *encrypted_message, int *date, int n) {
  int *date_key = date;
  int *date_end = date + n;
  char base;

  while (*message) {
    char ch = *message;

    if (islower(ch)) {
      base = 'a';
      *encrypted_message = ((ch - base + *date_key) % 26) + base;
      date_key++;
    } else if (isupper(ch)) {
      base = 'A';
      *encrypted_message = ((ch - base + *date_key) % 26) + base;
      date_key++;
    } else {
      *encrypted_message = ch;
    }

    if (date_key == date_end) {
      date_key = date;
    }

    message++;
    encrypted_message++;
  }

  *encrypted_message = '\0';
}
