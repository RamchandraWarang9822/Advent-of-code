#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char Hleft[4];
  char Hright[4];
};

unsigned long long int hash(char *str) {
  int first = str[0] - 64;
  int second = str[1] - 64;
  int third = str[2] - 64;
  unsigned long long int code = third + (second * 100) + (first * 10000);
  return code - 10101;
};

int main() {
  struct node nodes[252525];
  FILE *file;
  file = fopen("Ainput.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  int read = 0;

  // Read Instructions
  char instruction[1024];
  fgets(instruction, 1024, file);
  printf("Instructions : %s", instruction);

  // To skip blank line in input
  getline(&line, &len, file);

  unsigned long long firstHash = -1;
  // Store the hash value in node Array
  while ((read = getline(&line, &len, file)) != -1) {
    char key[4];
    char left[4];
    char right[4];
    sscanf(line, "%s = (%[^,], %[^)])", key, left, right);

    strcpy(nodes[hash(key)].Hleft, left);
    strcpy(nodes[hash(key)].Hright, right);
  }

  int counter = 0;
  unsigned long long int current = hash("AAA");
  while (current != 252525) {
    int direction = instruction[counter % (strlen(instruction) - 1)];
    if (direction == 76) {
      current = hash(nodes[current].Hleft);
    } else if (direction == 82) {
      current = hash(nodes[current].Hright);
    }
    counter++;
    printf("Current : %llu; direction: %d\n", current, direction);
  }

  printf("Result: %d", counter);

  fclose(file);
  return 0;
}
