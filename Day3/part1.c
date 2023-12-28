#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>



int main()
{
    FILE *file;
    file = fopen("input_part1.txt", "r");
    if (file == NULL)
    {
        printf("Error reading file\n");
        return 0;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file))
    {
        for (int i = 0; i < strlen(line); i++)
        {
            int number = 0;
            int j = i;
            while (isdigit(line[j]))
            {
                int current = line[j] - '0';
                number = number * 10 + current;
                j++;
            }
            if (number != 0)
            {
                printf("%d\n", number);
            }
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
