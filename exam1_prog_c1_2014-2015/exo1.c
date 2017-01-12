#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j, tmp;
    char occurence[26];

    if (argc < 2)
        return 0;

    for (i = 0; i < 26; i++)
        occurence[i] = 0;

    for (i = argc - 1; i > 0; i--)
    {
        for (j = 0; j < strlen(argv[i]); j++)
        {
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z') {
                tmp = (int) argv[i][j];
                occurence[tmp - 97] = occurence[tmp - 97] + 1;
            }
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (occurence[i] < 1)  
            continue;

        printf("%c : %d\n", i + 97, occurence[i]);
    }

    return 0;
}
