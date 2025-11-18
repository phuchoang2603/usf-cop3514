/*
 * This program manages tutor profiles using a dynamically allocated
 * linked list. Users can add tutors, search by level (elementary,
 * middle, or high school), print all tutors, and quit.
 *
 * author: Felix Hoang
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define LEVEL_LEN 30

struct tutor {
  char first[NAME_LEN + 1];
  char last[NAME_LEN + 1];
  char email[EMAIL_LEN + 1];
  int preferences[3];
  struct tutor *next;
};

struct tutor *add_to_list(struct tutor *list);
void search_list(struct tutor *list);
void print_list(struct tutor *list);
void clear_list(struct tutor *list);
int read_line(char str[], int n);

int main() {
  char code;

  struct tutor *tutor_list = NULL;
  printf("Operation Code: a for adding to the list, s for searching"
         ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') /* skips to end of line */
      ;
    switch (code) {
    case 'a':
      tutor_list = add_to_list(tutor_list);
      break;
    case 's':
      search_list(tutor_list);
      break;
    case 'p':
      print_list(tutor_list);
      break;
    case 'q':
      clear_list(tutor_list);
      return 0;
    default:
      printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct tutor *add_to_list(struct tutor *list) {

  struct tutor *cur, *new_node;

  new_node = malloc(sizeof(struct tutor));
  if (new_node == NULL) {
    printf("Database is full.\n");
    return list;
  }

  printf("Enter last name: ");
  read_line(new_node->last, NAME_LEN);
  printf("Enter first name: ");
  read_line(new_node->first, NAME_LEN);
  printf("Enter email address: ");
  read_line(new_node->email, EMAIL_LEN);
  printf("Enter preferences: ");
  scanf("%d %d %d", &new_node->preferences[0], &new_node->preferences[1],
        &new_node->preferences[2]);

  // Check if tutor already exists by email and last name
  for (cur = list; cur != NULL; cur = cur->next) {
    if (strcmp(cur->email, new_node->email) == 0 &&
        strcmp(cur->last, new_node->last) == 0) {
      printf("tutor already exists.\n");
      free(new_node);
      return list;
    }
  }

  // Set next pointer to NULL for new node
  new_node->next = NULL;

  // If list is empty, return the new node as the head
  if (list == NULL) {
    return new_node;
  }

  // Otherwise, add to the end of the list
  cur = list;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = new_node;

  return list;
}

void search_list(struct tutor *list) {
  // add new variables if necessary
  char level[LEVEL_LEN + 1];
  ;
  printf("Enter level: ");
  read_line(level, LEVEL_LEN + 1);

  struct tutor *cur;
  int found = 0;
  int level_index = -1;

  // Determine which level index to search for
  if (strcmp(level, "elementary") == 0) {
    level_index = 0;
  } else if (strcmp(level, "middle") == 0) {
    level_index = 1;
  } else if (strcmp(level, "high") == 0) {
    level_index = 2;
  }

  // Search through the list
  for (cur = list; cur != NULL; cur = cur->next) {
    if (level_index != -1 && cur->preferences[level_index] == 1) {
      printf("%-12s%-12s%-30s\n", cur->last, cur->first, cur->email);
      found = 1;
    }
  }

  if (!found) {
    printf("not found\n");
  }
}

void print_list(struct tutor *list) {

  struct tutor *cur;

  for (cur = list; cur != NULL; cur = cur->next) {
    printf("%-12s%-12s%-30s%5d%5d%5d\n", cur->last, cur->first, cur->email,
           cur->preferences[0], cur->preferences[1], cur->preferences[2]);
  }
}
void clear_list(struct tutor *list) {

  struct tutor *cur, *next;

  cur = list;
  while (cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
