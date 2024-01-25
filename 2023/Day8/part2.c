
#include <stdbool.h>
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
  file = fopen("input_part1.txt", "r");

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

  int *Aarray;
  int Asize = 1;
  // Store the hash value in node Array
  while ((read = getline(&line, &len, file)) != -1) {
    char key[4];
    char left[4];
    char right[4];
    sscanf(line, "%s = (%[^,], %[^)])", key, left, right);

    if (key[2] == 'A') {
      if (Aarray == NULL) {
        Aarray = (int *)malloc(Asize * sizeof(int));
        Asize++;
        Aarray[0] = hash(key);
      } else {
        Asize++;
        Aarray = (int *)realloc(Aarray, Asize * sizeof(int));
        Aarray[Asize - 1] = hash(key);
      }
    }

    strcpy(nodes[hash(key)].Hleft, left);
    strcpy(nodes[hash(key)].Hright, right);
  }

  for (int n = 0; n < Asize; n++) {
    printf("%d\n", Aarray[n]);
  }
  int counter = 0;

  for (int i = 0; i < strlen(instruction) - 1; i++) {
    counter++;
    int direction = instruction[i];
    int done = 0;
    for (int j = 0; j < Asize; j++) {
      char next[4];
      if (direction == 76) {
        strcpy(next, nodes[Aarray[j]].Hleft);
      } else if (direction == 82) {
        strcpy(next, nodes[Aarray[j]].Hright);
      }

      if (next[2] == 'Z') {
        done++;
      }

      if (done == Asize - 1) {
        printf("Result: %d", counter);
      }
    }
  }

  printf("Result: %d", counter);

  for (int m = 0; m < Asize; m++) {
    free(&Aarray[m]);
  }
  free(Aarray);
  fclose(file);
  return 0;
}
