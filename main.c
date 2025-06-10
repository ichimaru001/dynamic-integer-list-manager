#include <stdio.h>
#include <stdlib.h>

int checkListCapacityCount();

int main() {
  // TITLE        :     DYNAMIC INTEGER LIST MANAGER   
  // AUTHOR       :     ichimaru001
  // DATE         :     10/06/25
  // DESCRIPTION  :     ADD NUMBERS DYNAMICALLY TO A LIST, 
  //                    VIEW LIST, REMOVE NUMBER BY POSITION,
  //                    DOUBLE A NUMBER AT GIVEN POSITION,
  //                    FREE ALL MEMORY ON EXIT
  // TIME TAKEN   :     1HOUR 
  // TO COMPLETE


  char menuOptions[][50] = {
    "Add a number",
    "View Integer List",
    "Remove a number",
    "Double a number",
    "Exit the program"
  };
  int userChoice = 0;
  int integerListCount = 0;
  int integerListCapacity = 2;

  int *integerList = malloc(integerListCapacity * sizeof(int));
  if (integerList == NULL) {
    printf("\nMemory allocation failed!\n");
    return 1;
  }


  do
  {
    printf("\n*** DYNAMIC INTEGER LIST MANAGER ***\n");
    for (int i = 1; i <= sizeof(menuOptions) / sizeof(menuOptions[0]); i++)
    {
      printf("%d. %s\n", i, menuOptions[i - 1]);
    }
    printf("Enter your choice: ");
    scanf(" %d", &userChoice);

    if (userChoice == 1) {
      int userInteger = 0;
      printf("Enter an integer to be added to the list: ");
      scanf(" %d", &userInteger);

      // ** CHECK LIST CAPACITY AND COUNT
      checkListCapacityCount(integerListCount, &integerListCapacity, &integerList);
      // **

      integerList[integerListCount] = userInteger;
      integerListCount++;

      printf("\nSuccessfully added an integer!\n");
    }
    if (userChoice == 2) {
      printf("\n");
      for (int i = 1; i <= integerListCount; i++)
      {
        printf("%d. %d\n", i, integerList[i - 1]);
      }

      printf("\nSuccessfully loaded all the integers!\n");
    }
    if (userChoice == 3) {
      int userRemoveChoice = 0;

      printf("\n");
      for (int i = 1; i <= integerListCount; i++)
      {
        printf("%d. %d\n", i, integerList[i - 1]);
      }
      printf("Enter your choice to remove an integer: ");
      scanf(" %d", &userRemoveChoice);

      for (int i = userRemoveChoice - 1; i <= integerListCount; i++)
      {
        int tempInteger = integerList[i + 1];
        integerList[i] = tempInteger;
      }
      integerListCount--;
      printf("\nSuccessfully removed an integer!\n");
    }
    if (userChoice == 4) {
      int userDoubleChoice = 0;

      printf("\n");
      for (int i = 1; i <= integerListCount; i++)
      {
        printf("%d. %d\n", i, integerList[i - 1]);
      }
      printf("Enter your choice to double an integer: ");
      scanf(" %d", &userDoubleChoice);

      integerList[userDoubleChoice - 1] *= 2;
      printf("\nSuccessfully doubled an integer!\n");
    }
  } while (userChoice != 5);


  free(integerList);
  return 0;
}


int checkListCapacityCount(int integerListCount, int *integerListCapacity, int **integerList) {
  if (integerListCount >= *integerListCapacity) {
    *integerListCapacity *= 2;
    *integerList = realloc(*integerList, *integerListCapacity * sizeof(int));
    if (*integerList == NULL) {
      printf("\nMemory allocation failed!\n");
      return 1;
    }
    printf("\nMemory capacity reached!\nMemory expanded!\n");
  }
};