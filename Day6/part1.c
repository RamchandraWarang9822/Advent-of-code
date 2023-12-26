#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYLENGTH 4

int main() {

  int result = 1;
  FILE *file;
  file = fopen("input_part1.txt", "r");
  if (file == NULL) {
    printf("Error reading the input file");
    return 1;
  }

  // Extracting Time
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, file);

  char timeString[1024];
  sscanf(line, "Time: %[^\n]", timeString);
  char *timeToken = strtok(timeString, " ");
  int counter = 0;

  // Convert the time to integer;
  int timeArray[ARRAYLENGTH];
  while (timeToken != NULL) {
    timeArray[counter++] = atoi(timeToken);
    timeToken = strtok(NULL, " ");
  }

  printf("\nTime Array : ");
  for (int m = 0; m < ARRAYLENGTH; m++) {
    printf("%d ", timeArray[m]);
  }

  // Extracting distance
  getline(&line, &len, file);

  char distanceString[1024];
  sscanf(line, "Distance: %[^\n]", distanceString);
  char *distanceToken = strtok(distanceString, " ");
  counter = 0;

  // Convert the distance  to integer
  int distanceArray[ARRAYLENGTH];
  while (distanceToken != NULL) {
    distanceArray[counter++] = atoi(distanceToken);
    distanceToken = strtok(NULL, " ");
  }

  printf("\nDistance Array : ");
  for (int n = 0; n < ARRAYLENGTH; n++) {
    printf("%d ", distanceArray[n]);
  }

  for (int i = 0; i < counter; i++) {
    int time = timeArray[i];
    int distance = distanceArray[i];
    printf("CT : %d ; CD : %d\n", time, distance);
    int wins = 0;
    for (int speed = 0; speed < time; speed++) {
      int rem = time - speed;
      int tvl = speed * rem;
      wins = (tvl > distance) ? wins + 1 : wins;
    }
    printf("Wins: %d", wins);

    result = result * wins;
  }

  printf("Results: %d", result);

  fclose(file);
  return 0;
}
