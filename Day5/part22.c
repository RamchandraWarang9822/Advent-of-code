#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEEDS 20
#define NUM_THREADS 10

struct ThreadData {
  unsigned long long int startSeed;
  unsigned long long int endSeed;
  unsigned long long int result;
};

void *threadFunction(void *arg);
void processSeedsFromFile(FILE *file, unsigned long long int startSeed,
                          unsigned long long int endSeed,
                          unsigned long long int *result);

int main() {
  FILE *file;
  file = fopen("input_part1.txt", "r");
  if (file == NULL) {
    printf("Error reading the input file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;

  // Read the seeds
  getline(&line, &len, file);
  char seedString[1024];
  sscanf(line, "seeds: %[^\n]", seedString);
  char *token = strtok(seedString, " ");

  // Convert the seed to Integer
  unsigned long long int seeds[MAX_SEEDS];
  int counter = 0;
  while (token != NULL && counter < MAX_SEEDS) {
    seeds[counter++] = strtoull(token, NULL, 10);
    token = strtok(NULL, " ");
  }

  fclose(file);

  // Create an array to hold thread data
  struct ThreadData threadData[NUM_THREADS];

  // Create threads and assign work
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; ++i) {
    threadData[i].startSeed = seeds[i * 2];
    threadData[i].endSeed = seeds[i * 2] + seeds[i * 2 + 1];
    pthread_create(&threads[i], NULL, threadFunction, (void *)&threadData[i]);
  }

  // Wait for threads to finish
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  // Find the minimum result from all threads
  unsigned long long int finalResult = threadData[0].result;
  for (int i = 1; i < NUM_THREADS; ++i) {
    if (threadData[i].result < finalResult) {
      finalResult = threadData[i].result;
    }
  }

  printf("Final Result : %llu\n", finalResult);

  return 0;
}

void *threadFunction(void *arg) {
  struct ThreadData *data = (struct ThreadData *)arg;
  processSeedsFromFile("input_part1.txt", data->startSeed, data->endSeed,
                       &(data->result));
  pthread_exit(NULL);
}

void processSeedsFromFile(const char *filename,
                          unsigned long long int startSeed,
                          unsigned long long int endSeed,
                          unsigned long long int *result) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error reading the input file");
    return;
  }

  unsigned long long int localResult = 0;

  for (unsigned long long int i = startSeed; i < endSeed; ++i) {
    // Rest of your logic here...
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
  }

  // Update the result in the thread data structure
  *result = localResult;

  fclose(file);
}
