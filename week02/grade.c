#include <stdio.h>

int main () {
	int grade;
	printf ("Enter grade: ");
	scanf ("%d", &grade);

	if (grade > 0 && grade < 5) 
		printf ("Passing.\n");
	else if (grade == 0)
		printf ("Failing.\n");
	else
		printf ("Illegal grade.\n");
	return 0;
}
