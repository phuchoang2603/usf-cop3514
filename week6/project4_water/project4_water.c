/*
 * This program checks if the water usage for the current month is unusual
 * compared to the average of the last 10 months by using pointers.
 * Author: Felix Hoang
 */

#include <math.h>
#include <stdio.h>

#define NUM_MONTHS 10

double average(double *usage, int n);
double standard_deviation(double *usage, double avg, int n);

int main() {
  double current_month_usage;
  double last_usage[NUM_MONTHS];
  double avg;
  double std_dev;

  // Get water usage for the current month
  printf("Enter water usage for this month:");
  scanf("%lf", &current_month_usage);

  // Get water usage for the last 10 months
  printf(" Enter water usage for the last 10 months: ");
  for (int i = 0; i < NUM_MONTHS; i++) {
    scanf("%lf", &last_usage[i]);
  }

  // Call functions to get the average and standard deviation
  avg = average(last_usage, NUM_MONTHS);
  std_dev = standard_deviation(last_usage, avg, NUM_MONTHS);

  // Check if usage is more than 2 standard deviations from the average.
  if (fabs(current_month_usage - avg) > (2 * std_dev)) {
    printf(" Unusual usage.\n");
  } else {
    printf(" Normal usage.\n");
  }

  return 0;
}

double average(double *usage, int n) {
  double sum = 0.0;
  double *ptr_end = usage + n;

  for (; usage < ptr_end; usage++) {
    sum += *usage;
  }

  return sum / n;
}

double standard_deviation(double *usage, double avg, int n) {
  double sum_of_squares = 0.0;
  double *ptr_end = usage + n;

  for (; usage < ptr_end; usage++) {
    sum_of_squares += (*usage - avg) * (*usage - avg);
  }

  if (n > 1) {
    return sqrt(sum_of_squares / (n - 1));
  } else {
    return 0.0;
  }
}
