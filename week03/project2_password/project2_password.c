/*
 * This program checks if a password is valid based on the following criteria:
 * - Only alphanumeric characters
 * - At least 8 characters long
 * - At least one uppercase letter and one lowercase letter
 * author: Felix Hoang
 */

#include <stdio.h>
#include <ctype.h>

int main () {
	char ch;
	int is_valid = 1;
	int length = 1; // already include line break
	int has_upper = 0;
	int has_lower = 0;
	printf ("Enter input: ");
	
	ch = getchar();
	
	while (ch != '\n') {
		length++;

		// Check if character is a alphanumeric
		if (!(isdigit(ch) || isalpha(ch))) is_valid = 0;

		// Check if contains at least one uppercase and one lowercase letter
		if (islower(ch)) has_lower = 1;
		if (isupper(ch)) has_upper = 1;

		ch = getchar();
	}

	// Check if password length is at least 8 characters and if it has upper and lower case letters
	if (!(length>8 && has_upper && has_lower) ) is_valid = 0;

	if (is_valid) printf ("Valid");
	else printf ("Invalid");

	return 0;
}
