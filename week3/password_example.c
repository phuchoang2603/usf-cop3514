#include <stdio.h>

int main () {
	char ch;
	int is_valid = 1;
	printf ("Enter password:");
	
	ch = getchar();
	printf ("%c", ch);
	int count = 1;
	
	while (ch != '\n') {
		count++;
		if (!(ch >= 'a' && ch <= 'z') || (ch >= 'a' && ch <= 'z') || (ch >= 'a' && ch <= 'z')) is_valid = 0;

		ch = getchar();
		printf("%c", ch);
	}

	if (count<8) is_valid = 0;

	if (is_valid) printf ("\nValid\n");
	else printf ("\nInvalid\n");

	return 0;
}
