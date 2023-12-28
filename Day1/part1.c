#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    char buffer[1024];

    file = fopen("./input_part1.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    int sum = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int first = -1, last = -1;
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] >= 48 && buffer[i] <= 57)
            {
                // convert char to integer
                if (first == -1)
                {
                    first = buffer[i] - '0';
                }
                last = buffer[i] - '0';
            }
        }
        int curr = (first * 10) + last;
        sum += curr;
    }
    printf("%d\n", sum);
    fclose(file);
    return 0;
}
