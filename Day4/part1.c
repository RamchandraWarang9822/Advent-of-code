#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include <ctype.h>

int main()
{
    FILE *file;
    file = fopen("./input_part1.txt", "r");
    if (file == NULL)
    {
        printf("Error reading the input file");
        return 1;
    }

    char line[1024];
    int cardId = 0;
    char cardString[1024];
    int result = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "Card %d: %[^\n]", &cardId, cardString) != 2)
        {
            printf("Error read the line : %d", cardId);
            continue;
        }

        char *winningString = NULL;
        char *numberString = NULL;
        char *proxyString = (char *)malloc(strlen(cardString) + 1);
        strcpy(proxyString, cardString);

        winningString = strtok(cardString, "|");
        numberString = strtok(NULL, "");

        int winning[10];
        char *winningToken = strtok(winningString, " ");
        int i = 0;
        while (winningToken != NULL)
        {
            winning[i++] = atoi(winningToken);
            winningToken = strtok(NULL, " ");
        }

        int number[25];
        char *numberToken = strtok(numberString, " ");
        int j = 0;
        while (numberToken != NULL)
        {
            number[j++] = atoi(numberToken);
            numberToken = strtok(NULL, " ");
        }

        int points = 0;

        for (int n = 0; n < 25; n++)
        {
            for (int m = 0; m < 10; m++)
            {
                if (number[n] == winning[m])
                {
                    printf("Matching Number : %d\nWinning number : %d\n\n", number[n], winning[m]);
                    points = ( points == 0) ? 1 : points * 2;
                }
            }
        }
        result += points;
    }

    printf("Result : %d", result);
    fclose(file);
}
