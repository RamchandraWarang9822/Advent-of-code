#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5

int main(int argc, char *argv[]) {
  char *filename;
  if (argc >= 2) {
    filename = argv[1];
  } else {
    printf("Error: plz input filename");
    return EXIT_FAILURE;
  }
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    perror("ERROR OPENING FILE");
    return EXIT_FAILURE;
  }

  char *line;
  size_t len = 0;
  int lineCount = 0;
  char arr[ROWS][COLS];
  unsigned long long int result = 0;

  int sX = -1;
  int sY = -1;

  // Convert input file to 2D array
  while (getline(&line, &len, file) != -1) {
    printf("%s", line);
    for (int i = 0; i < COLS; i++) {
      if (line[i] == 'S') {
        sX = lineCount;
        sY = lineCount;
      }
      arr[lineCount][i] = line[i];
    }
    lineCount++;
  }

  printf("S[%d][%d] ", sX, sY);

  fclose(file);
  return 0;
}
