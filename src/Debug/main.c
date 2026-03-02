//#ifdef DEBUG

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Rope.h"

void DebugRope();

int main(int argc, char* argv[]) {
  if (argc > 2 || argc <= 1) {
    printf("ERROR: Only one argument is allowed for debugging purposes\n");
  }

  printf("Number of arguments: %d\n", argc);
  for (int i = 0; i < argc; ++i) {
    printf("Argument %d: %s\n", i, argv[i]);
  }

  while (true) {
    if (strcmp(argv[1], "Rope") == EXIT_SUCCESS) {
      DebugRope();
    } else {
      return 0;
    }
  }
}

void DebugRope() {
  char string[400] = {0};
  t_rope* rope = (t_rope*)malloc(sizeof(t_rope));

  printf("Enter a string to create a rope: ");
  fgets(string, sizeof(string), stdin);

  // fgets() keeps the newline character '\n'. To remove it:
  string[strcspn(string, "\n")] = 0; 

  printf("Creating Rope...\n");
  Create(rope, NULL, string, 0, strlen(string) - 1);

  int optionSelected;
  printf("Do you want to do something else?\n");
  printf("1. Generate a new rope\n");
  printf("2. Print all leaves\n");
  printf("3. Concatenate new string\n");
  printf("4. Search for a specific index\n");
  scanf("%d", &optionSelected);
  printf("\nYou selected Option %d", optionSelected);
}

//#endif