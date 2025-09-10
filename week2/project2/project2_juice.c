/*
 * This program replicate a simple vending machine that accepts coins and dispenses orange juice.
 * author: Felix Hoang
 */

#include <stdio.h>

#define SMALL_CUP 75
#define LARGE_CUP 125

int main (){
  // Reading coins until user inputs 0
  int coin;
  int total = 0;
  int change;

  do {
    printf("Insert coins: ");
    scanf("%d", &coin);
    
    total += coin;
  } while (coin != 0);

  // Prompt user to select juice
  int juice;
  printf("Please select 1 for a small cup and 2 for a large cup: ");
  scanf("%d", &juice);

  // Calculate change based on selection
  switch (juice) {
    case 1:
      change = total - SMALL_CUP;
      break;
    case 2:
      change = total - LARGE_CUP;
      break;
    default:
      printf("Invalid selection.\n");
      return 1;
  }

  if ( change < 0 ) {
    printf("Insufficient amount.\n");
    change = total; // return all money
    printf("Your change is %d cents. Collect your change at the bottom.\n", change);

  } else if (change == 0) {
    printf("Collect your juice and enjoy!\n");
  }

  else {
    printf("Collect your juice and enjoy!\n");
    printf("Your change is %d cents. Collect your change at the bottom.\n", change);
  }

	return 0;
}
