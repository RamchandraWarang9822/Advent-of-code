// This code is not working
#include <stdio.h>

int main()
{
    FILE *file;
    char buffer[100];

    file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    int sum = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int first = -1, last = -1;
        printf("%s", buffer);
        for (int i = 0; i < sizeof(buffer); i++)
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
