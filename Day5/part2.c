#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEEDS 20

int main() {
  FILE *file;
  file = fopen("input_part1.txt", "r");
  if (file == NULL) {
    printf("Error reading the input file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  unsigned long long int result = 0;

  // Read the seeds
  getline(&line, &len, file);
  char seedString[1024];
  sscanf(line, "seeds: %[^\n]", seedString);
  char *token = strtok(seedString, " ");

  // Convert the seed to Integer
  unsigned long long int seeds[MAX_SEEDS];
  int counter = 0;
  while (token != NULL) {
    seeds[counter++] = strtoull(token, NULL, 10);
    token = strtok(NULL, " ");
  }

  // Using seed find the location
  for (int k = 0; k < MAX_SEEDS; k = k + 2) {

    for (unsigned long long int i = seeds[k]; i < seeds[k] + seeds[k + 1];
         i = i + 1) {
      unsigned long long int value = i;
      printf("Current Seed: %llu\n", i);

      if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error seeking file");
        fclose(file);
        return 1;
      }

      char currLine[1024];

      if (fgets(currLine, sizeof(currLine), file) == NULL ||
          fgets(currLine, sizeof(currLine), file) == NULL) {
        perror("Error reading from file");
        fclose(file);
        return 1;
      }

      bool flag = false;

      while (fgets(currLine, sizeof(currLine), file)) {

        if (currLine[0] == '\n') {
          fgets(currLine, sizeof(currLine), file);
          printf("\n");
          flag = false;
          continue;
        }
        // Convert Numbers to Integer Array
        unsigned long long int dest = 0;
        unsigned long long int src = 0;
        unsigned long long int rng = 0;
        sscanf(currLine, "%llu %llu %llu", &dest, &src, &rng);
        // printf("%llu %llu %llu\n", dest, src, rng);

        if (value <= src + rng && value >= src && flag == false) {
          unsigned long long int diff = value - src;
          value = dest + diff;
          // printf("Value changed to: %llu\n", value);
          flag = true;
        }
      }

      if (result == 0) {
        result = value;
      } else if (result > value) {
        result = value;
      }
      printf("End of the loop Result :%llu\n", result);
    }
  }
  printf("Final Result : %llu\n", result);

  fclose(file);
  return 0;
}
