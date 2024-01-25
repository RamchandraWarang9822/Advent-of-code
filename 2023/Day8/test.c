#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  file = fopen("input_part1.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char instruction[1024];
  fgets(instruction, 1024, file);
  printf("Instructions : %s", instruction);

  int counter = 0;
  while (counter < strlen(instruction) * 2) {
    printf("%s ", instruction[counter++ % strlen(instruction)]);
  }

  fclose(file);
  return 0;
}
