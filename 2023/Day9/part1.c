#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(unsigned long long int *arr, int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += arr[i];
  }
  return total;
}

void extrapolate(unsigned long long int *arr, int size, int fCount,
                 unsigned long long int **firstArray) {

  if (size == 0) {
    return;
  }

  *firstArray[fCount] = arr[0];
  fCount++;

  *firstArray = (unsigned long long int *)realloc(
      *firstArray, sizeof(unsigned long long int) * (fCount));

  for (int i = 0; i < size - 1; i++) {
    arr[i] = arr[i + 1] - arr[i];
  }

  extrapolate(arr, size - 1, fCount, firstArray);
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
  unsigned long long int result = 0;

  while (getline(&line, &len, file) != -1) {
    int counter = 0;
    int capacity = 5;
    unsigned long long int arr[21];
    char *token = strtok(line, " ");
    while (token != NULL) {
      arr[counter++] = atoi(token);
      token = strtok(NULL, " ");
    }

    unsigned long long int *firstArray = malloc(sizeof(unsigned long long int));
    int fCount = 0;
    extrapolate(arr, counter, fCount, &firstArray);

    for (int t = 0; t < sizeof(firstArray) / 4; t++) {
      printf("New %llu", firstArray[t]);
    }
    printf("\n");

    result += sum(arr, counter);
  }

  printf("Final Result  : %llu\n", result);

  fclose(file);
  return EXIT_SUCCESS;
}
