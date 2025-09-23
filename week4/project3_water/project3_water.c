/*
 * This program check if there is an water leak in a household
 * in current month compare to over 10 months.
 * Author: Felix Hoang
 */

#include <math.h>
#include <stdio.h>

// This function compute and return
// the average of the water usage over 10 months
double average(double usage[], int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += usage[i];
  }
  return sum / n;
}

// This function compute and return
// the standard deviation of the water usage over n months
double standard_deviation(double usage[], double avg, int n) {
  double sum_squared_diff = 0;
  for (int i = 0; i < n; i++) {
    sum_squared_diff += (usage[i] - avg) * (usage[i] - avg);
  }
  double standard_dev = sqrt(sum_squared_diff / (n - 1));
  return standard_dev;
}

int main() {
  printf("Enter water usage for this month:");
  double current_month_usage;
  scanf("%lf", &current_month_usage);

  printf("Enter water usage for the last 10 months:");
  double last_10_months_usage[10];
  for (int i = 0; i < 10; i++) {
    scanf("%lf", &last_10_months_usage[i]);
  }

  double mean = average(last_10_months_usage, 10);
  double stddev = standard_deviation(last_10_months_usage, mean, 10);

  double threshold = mean + 2 * stddev;

  (current_month_usage > threshold) ? printf("Unusual usage.")
                                    : printf("Normal usage.");

  return 0;
}
