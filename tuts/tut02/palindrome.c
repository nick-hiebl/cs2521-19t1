#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(char *word) {
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Correct usage: %s <word>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (isPalindrome(argv[1])) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return EXIT_SUCCESS;
}
