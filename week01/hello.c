/* 
 * This program calculates the pay
 * for a hourly employee.
 * author: ...
*/
#include <stdio.h>

#define HOURLY_RATE 21.50

int main (){
	int hours;
	printf ("Enter the hours: ");
	scanf("%d", &hours);

	double pay = HOURLY_RATE * hours;

	printf ("pay of %.2f.\n", pay);
	return 0;
}
