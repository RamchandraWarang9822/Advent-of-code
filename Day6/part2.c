#include <stdio.h>

int main() {

  unsigned long long int result = 1;
  unsigned long long int time = 54708275;
  unsigned long long int distance = 239114212951253;
  unsigned long long int wins = 0;
  for (unsigned long long int speed = 0; speed < time; speed++) {
    unsigned long long int rem = time - speed;
    unsigned long long int tvl = speed * rem;
    wins = (tvl > distance) ? wins + 1 : wins;
  }

  result = wins;

  printf("Results: %llu", result);

  return 0;
}
