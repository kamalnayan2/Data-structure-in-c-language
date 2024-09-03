#include <stdio.h>
#include <string.h>
#define MAX 10
#define LEN 20
void bubbleSort(char names[][LEN], int n) {

  int i, j;
  char temp[20];
  
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      
      if (strcmp(names[j], names[j + 1]) > 0) {
      strcpy(temp, names[j]);
      strcpy(names[j],names[j+1]);
      strcpy(names[j+1], temp);

      }
    }
  }
}

void printArray(char names[][LEN], int size) {

  for (int i = 0; i < size; i++) {
    printf("%s\n", names[i]);
  }
}
void main() {
  char names[MAX][LEN];
  int n;
  int i;
 printf("Enter the number of names (max %d): ", MAX);
 scanf("%d", &n);
 if (n < 1 || n > MAX) {
 printf("Invalid number of names\n");
  }
 printf("Enter %d names: \n", n);
 for (i = 0; i < n; i++) {
 scanf("%s", names[i]);
  }
 bubbleSort(names, n);
 printf("The sorted names are: \n");
 for (i = 0; i < n; i++) {
 printf("%s\n", names[i]);
  }
 getch();
}
