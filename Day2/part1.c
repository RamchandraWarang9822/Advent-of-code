#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *gameRound)
{
    char *round = NULL;
    char *proxyString = (char *)malloc(strlen(gameRound) + 1);
    strcpy(proxyString, gameRound);

    round = strtok(gameRound, ";");
    while (gameRound != NULL)
    {
        while (round != NULL)
        {
            char *singleGame = strtok(round, ",");
            while (singleGame != NULL)
            {
                char *amount = strtok(singleGame, " ");
                char Iamount = atoi(amount);
                char *color = strtok(NULL, " ");

                if (strcmp(color, "red") == 0)
                {
                    if (Iamount > 12)
                    {
                        return false;
                    }
                }
                else if (strcmp(color, "green") == 0)
                {
                    if (Iamount > 13)
                    {
                        return false;
                    }
                }
                else if (strcmp(color, "blue") == 0)
                {
                    if (Iamount > 14)
                    {
                        return false;
                    }
                }
                else
                {
                    return true;
                }
                singleGame = strtok(NULL, ",");
            }
            round = strtok(NULL, ";");
        }
        strcpy(gameRound, proxyString);
        round = strtok(NULL, ";");
        if (round == NULL)
        {
            gameRound = NULL;
        }
    }
    free(proxyString);
}

int main()
{
    FILE *file;
    file = fopen("./input_part1.txt", "r");
    if (file == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    char line[1024];
    int gameId = 0;
    char gameString[1024];
    int trueSum = 0;
    int falseSum = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "Game %d: %[^\n]", &gameId, gameString) != 2)
        {
            printf("Error reading the line : %d", gameId);
            continue;
        }
        if (isValid(gameString))
        {
            trueSum += gameId;
        }
    }
    printf("Total no. of possible game : %d", trueSum);

    fclose(file);
    return 0;
}