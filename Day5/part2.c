#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEEDS 20

// Structure to pass arguments to the thread function
struct ThreadArgs {
  FILE *file;
  unsigned long long int *seeds;
  int startIdx;
  int endIdx;
  unsigned long long int *minResult; // Shared minimum result
  pthread_mutex_t *mutex;            // Mutex for synchronization
};

// Function to be executed by each thread
void *process_seeds(void *args) {
  struct ThreadArgs *threadArgs = (struct ThreadArgs *)args;

  unsigned long long int localMinResult = ULLONG_MAX;

  for (int k = threadArgs->startIdx; k < threadArgs->endIdx; k = k + 2) {
    for (unsigned long long int i = threadArgs->seeds[k];
         i < threadArgs->seeds[k] + threadArgs->seeds[k + 1]; i = i + 1) {
      unsigned long long int value = i;
      printf("Thread %lu - Current Seed: %llu\n", pthread_self(), i);

      if (fseek(threadArgs->file, 0, SEEK_SET) != 0) {
        perror("Error seeking file");
        fclose(threadArgs->file);
        pthread_exit(NULL);
      }

      char currLine[1024];

      if (fgets(currLine, sizeof(currLine), threadArgs->file) == NULL ||
          fgets(currLine, sizeof(currLine), threadArgs->file) == NULL) {
        perror("Error reading from file");
        fclose(threadArgs->file);
        pthread_exit(NULL);
      }

      bool flag = false;

      while (fgets(currLine, sizeof(currLine), threadArgs->file)) {
        if (currLine[0] == '\n') {
          fgets(currLine, sizeof(currLine), threadArgs->file);
          printf("\n");
          flag = false;
          continue;
        }

        // Convert Numbers to Integer Array
        unsigned long long int dest = 0;
        unsigned long long int src = 0;
        unsigned long long int rng = 0;
        sscanf(currLine, "%llu %llu %llu", &dest, &src, &rng);

        if (value <= src + rng && value >= src && flag == false) {
          unsigned long long int diff = value - src;
          value = dest + diff;
          flag = true;
        }
      }

      // Update local minimum result
      if (localMinResult > value) {
        localMinResult = value;
      }

      printf("Thread %lu - End of the loop Result :%llu\n", pthread_self(),
             localMinResult);
    }
  }

  // Update shared minimum result using mutex
  pthread_mutex_lock(threadArgs->mutex);
  if (*(threadArgs->minResult) > localMinResult) {
    *(threadArgs->minResult) = localMinResult;
  }
  pthread_mutex_unlock(threadArgs->mutex);

  pthread_exit(NULL);
}

int main() {
  FILE *file;
  file = fopen("input_part1.txt", "r");
  if (file == NULL) {
    printf("Error reading the input file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;

  unsigned long long int result = ULLONG_MAX; // Shared minimum result
  pthread_mutex_t resultMutex =
      PTHREAD_MUTEX_INITIALIZER; // Mutex for synchronization

  getline(&line, &len, file);
  char seedString[1024];
  sscanf(line, "seeds: %[^\n]", seedString);
  char *token = strtok(seedString, " ");

  unsigned long long int seeds[MAX_SEEDS];
  int counter = 0;
  while (token != NULL) {
    seeds[counter++] = strtoull(token, NULL, 10);
    token = strtok(NULL, " ");
  }

  // Number of threads
  int numThreads = MAX_SEEDS / 2;
  pthread_t threads[numThreads];
  struct ThreadArgs threadArgs[numThreads];

  // Create threads
  for (int i = 0; i < numThreads; ++i) {
    threadArgs[i].file = file;
    threadArgs[i].seeds = seeds;
    threadArgs[i].startIdx = i * 2;
    threadArgs[i].endIdx = (i + 1) * 2;
    threadArgs[i].minResult = &result;
    threadArgs[i].mutex = &resultMutex;

    if (pthread_create(&threads[i], NULL, process_seeds, &threadArgs[i]) != 0) {
      perror("Error creating thread");
      exit(EXIT_FAILURE);
    }
  }

  // Wait for all threads to finish
  for (int i = 0; i < numThreads; ++i) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("Error joining thread");
      exit(EXIT_FAILURE);
    }
  }

  // Close the file after all threads have completed
  fclose(file);

  printf("Final Result : %llu\n", result);

  return 0;
}
