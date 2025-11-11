#include <stdio.h>

int main () {
	char ch;
	int is_valid = 1;
	int length = 1;
	printf ("Enter password:");
	
	ch = getchar();
	printf ("%c", ch);
	
	while (ch != '\n') {
		length++;
		if (!((ch >= 'a' && ch <= 'z') || (ch >= 'a' && ch <= 'z') || (ch >= 'a' && ch <= 'z'))) is_valid = 0;

		ch = getchar();
		printf("%c", ch);
	}

	if (length<8) is_valid = 0;

	if (is_valid) printf ("\nValid\n");
	else printf ("\nInvalid\n");

	return 0;
}
