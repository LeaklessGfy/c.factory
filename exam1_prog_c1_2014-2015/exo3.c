#include <stdio.h>
#include <string.h>

/* gcc -o test exo3.c -Wall -ansi */
int main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("Pas assez d'arguments\n");
        return 1;
    }

    for (i = strlen(argv[1]) - 1; i > -1; i--)
        printf("%c", argv[1][i]);

    printf("\n");

    return 0;
}
