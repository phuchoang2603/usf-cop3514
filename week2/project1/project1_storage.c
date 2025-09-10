/*
 * This program calculates the cost for a storage
 * author: Felix Hoang
 */

#include <stdio.h>

int main() {
	// Define variables
	int storage_selection;
	int months;
	int years;

	int first_month_rate;
	int monthly_rate;
	int year_rate;

	int charge;

	// Prompt user for storage selection, validate if it is in [1,4]
	printf("Please select from four types of storage units: 1, 2, 3, and 4\n");
	printf("Enter storage selection:");
	scanf("%d", &storage_selection);
	if (storage_selection < 1 || storage_selection > 4) {
		printf ("Invalid selection. Select from 1 to 4.");
		return 0;
	}

	// Prompt user for months, validate if it is > 0
	printf("Enter months:");
	scanf("%d", &months);
	if (months <= 0) {
		printf ("Invalid months.");
		return 0;
	}
	years = months / 12;

	// Convert predefined table to variable values
	switch (storage_selection) {
		case 1: first_month_rate = 0;
			monthly_rate = 40;
			year_rate = 400;
			break;
		case 2: first_month_rate = 25;
			monthly_rate = 50;
			year_rate = 500;
			break;
		case 3: first_month_rate = 40;
			monthly_rate = 100;
			year_rate = 800;
			break;
		case 4: first_month_rate = 60;
			monthly_rate = 150;
			year_rate = 1200;
			break;
	}
	
	// Calculate the charge based on years and months
	if (years == 0) {
		// logic for rentals of 1 year or less
		if (months == 1)
			charge = first_month_rate;
		else
			charge = first_month_rate + monthly_rate * (months - 1);
		// apply yearly maximum cap
		if (charge > year_rate)
			charge = year_rate;
	}
	else {
		// logic for rentals more than a year - first month rate not apply
		charge = years * year_rate;

		int remain_months = months % 12;
		int remain_months_charge = remain_months * monthly_rate;

		// apply yearly maximum cap
		if (remain_months_charge > year_rate)
			remain_months_charge = year_rate;

		charge += remain_months_charge;
	}

	printf ("Charge($):%d", charge);

	return 0;
}
