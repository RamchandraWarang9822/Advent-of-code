#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part1(FILE *file)
{
  char *line = NULL;
  size_t len = 0;
  int result = 0;

  while (getline(&line, &len, file) != -1)
  {
    int min, max;
    char key;
    char password[1024];

    sscanf(line, "%d-%d %c: %s", &min, &max, &key, password);

    int i = 0, counter = 0;
    while (password[i] != '\0')
    {
      if (password[i] == key)
        counter++;
      i++;
    }

    if (counter >= min && counter <= max)
    {
      result++;
    }
  }
  printf("%d", result);
}

void part2(FILE *file)
{
  char *line = NULL;
  size_t len = 0;
  int result = 0;

  while (getline(&line, &len, file) != -1)
  {
    int min, max;
    char key;
    char password[1024];

    sscanf(line, "%d-%d %c: %s", &min, &max, &key, password);

    if (password[min - 1] == key ^ password[max - 1] == key)
    {
      result++;
    }
  }
  printf("%d", result);
}

int main()
{
  FILE *file;
  file = fopen("input.txt", "r");
  if (file == NULL)
  {
    printf("Error reading the input file");
    return 1;
  }

  // part1(file);
  part2(file);

  return 0;
}