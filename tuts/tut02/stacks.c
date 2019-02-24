#include <stdio.h>
#include <stdlib.h>

int findMost(int A[], int n, int B[], int m, int k);

int main(void) {
  int stack1[5] = {1, 6, 4, 2, 4};
  int n = 5;
  int stack2[4] = {5, 8, 1, 2};
  int m = 4;
  int k = 7;

  int items = findMost(stack1, n, stack2, m, k);

  printf("The most items you can take is %d\n", items);
  if (items == 0) {
    printf(":(\n");
  }

  return EXIT_SUCCESS;
}

int findMost(int A[], int n, int B[], int m, int k) {
  return 0;
}
