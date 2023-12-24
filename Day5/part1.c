#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  file = fopen("./input_part1.txt", "r");
  if (file == NULL) {
    printf("Error reading the input file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  int result = 0;

  // Read the seeds
  getline(&line, &len, file);
  char seedString[1024];
  sscanf(line, "seeds: %[^\n]", seedString);
  char *token = strtok(seedString, " ");

  // Convert the seed to Integer
  int seeds[4];
  int counter = 0;
  while (token != NULL) {
    seeds[counter++] = atoi(token);
    token = strtok(NULL, " ");
  }

  for (int i = 0; i < 4; i++) {
    int value = seeds[i];
    printf("Current Seed: %d", value);

    if (fseek(file, 3, SEEK_SET) != 0) {
      perror("Error seeking file");
      fclose(file);
      return 1;
    }

    char currLine[1024];

    while (fgets(currLine, sizeof(currLine), file)) {
      if (currLine[0] == '\n') {
        fgets(currLine, sizeof(currLine), file);
        printf("\n");
        continue;
      }
      // Convert Numbers to Integer Array
      int dest = 0;
      int src = 0;
      int rng = 0;
      sscanf(currLine, "%d %d %d", &dest, &src, &rng);
      printf("%d %d %d\n", dest, src, rng);

      if (value <= src + rng && value >= src) {
        int diff = value - src;
        value = dest + diff;
        printf("Value changed to: %d\n", value);
      }
    }

    if (result == 0) {
      result = value;
    } else if (value < result) {
      result = value;
    }
  }

  printf("Final Result : %d\n", result);

  // Reading Source , Destination and Range
  // char currLine[1024];
  // while (fgets(currLine, sizeof(currLine), file)) {
  //   if (currLine[0] == '\n') {
  //     fgets(currLine, sizeof(currLine), file);
  //     printf("\n");
  //     continue;
  //   }
  //   // Convert Numbers to Integer Array
  //   int nums[3];
  //   sscanf(currLine, "%d %d %d", &nums[0], &nums[1], &nums[2]);
  //
  //   // Print the Integer Array
  //   for (int i = 0; i < 3; i++) {
  //     printf("%d ", nums[i]);
  //   }
  //   printf("\n");
  // }

  fclose(file);
  return 0;
}
