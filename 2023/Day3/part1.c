#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 140
#define COLS 140

bool isSymbol(char s) {
  const char symbolSet[] = {'!', '@', '#', '$', '%', '^',  '&', '*', '(', ')',
                            '-', '+', '=', '{', '}', '[',  ']', ';', ':', '<',
                            '>', ',', '/', '?', '|', '\\', '`', '~'};

  // Check if the character is in the symbol set (excluding '.')
  for (int i = 0; i < sizeof(symbolSet) / sizeof(symbolSet[0]); i++) {
    if (s == symbolSet[i] && s != '.') {
      return true;
    }
  }

  return false;
}

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

  // Convert input file to 2D array
  while (getline(&line, &len, file) != -1) {
    printf("%s", line);
    for (int i = 0; i < COLS; i++) {
      arr[lineCount][i] = line[i];
    }
    lineCount++;
  }

  for (int m = 0; m < ROWS; m++) {
    for (int n = 0; n < COLS; n++) {
      int number = 0;
      bool partNum = false;
      while (isdigit(arr[m][n])) {
        // Checker function
        // Top row
        if (m != 0) {
          if (n != 0) {
            char a = arr[m - 1][n - 1];
            partNum = (partNum == false) ? isSymbol(a) : partNum;
          }
          char b = arr[m - 1][n];
          partNum = (partNum == false) ? isSymbol(b) : partNum;
          if (n < COLS) {
            char c = arr[m - 1][n + 1];
            partNum = (partNum == false) ? isSymbol(c) : partNum;
          }
        }

        // Middle row
        if (n != 0) {
          char d = arr[m][n - 1];
          partNum = (partNum == false) ? isSymbol(d) : partNum;
        }
        if (n < COLS) {
          char e = arr[m][n + 1];
          partNum = (partNum == false) ? isSymbol(e) : partNum;
        }

        // Bottom row
        if (m < ROWS) {
          if (n != 0) {
            char f = arr[m + 1][n - 1];
            partNum = (partNum == false) ? isSymbol(f) : partNum;
          }
          char g = arr[m + 1][n];
          partNum = (partNum == false) ? isSymbol(g) : partNum;
          if (n < COLS) {
            char h = arr[m + 1][n + 1];
            partNum = (partNum == false) ? isSymbol(h) : partNum;
          }
        }

        int current = arr[m][n] - '0';
        number = number * 10 + current;
        n++;
      }
      if (number != 0) {

        if (partNum == true) {
          printf("Part number: %d\n", number);
          result += number;
        }
        // printf("%d\n", number);
      }
    }
    printf("\n");
  }

  printf("Result : %llu", result);
  fclose(file);
  return 0;
}
