#include <stdio.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5

int main (){
	int cents;
	int quarters;
	int dimes;
	int nickels;
	int pennies;

	printf ("Enter cents: ");
	scanf ("%d", &cents);

	if (cents < 0 || cents > 10000) {
		printf ("Enter a positive number.\n");
	}
	else {
		quarters = cents / QUARTER;
		cents = cents % QUARTER;
		dimes = cents / DIME;
		cents = cents % DIME;
		nickels = cents / NICKEL;
		pennies = cents % NICKEL;
	}

	printf ("Quarters: %d, Dimes: %d, Nickels: %d, Pennies: %d \n", quarters, dimes, nickels, pennies);

	return 0;
}
