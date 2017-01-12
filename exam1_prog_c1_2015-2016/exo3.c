#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strange(char *arg)
{
    if (arg[0] == '\0')
    {
        printf("\n");
        return;
    }

    printf("%c", arg[strlen(arg)-1]);
    arg[strlen(arg)-1] = '\0';
    strange(arg);
}

void strange2(char *arg)
{
    int len, i;

    len = strlen(arg);

    for (i = len-1; i > -1; i--)
        printf("%c", arg[i]);

    printf("\n");
}

int main(int argc, char *argv[])
{
    char *tmp;
    int len;

    len = strlen(argv[1]);
    tmp = (char*) malloc(sizeof(char) * (len + 1));
    strcpy(tmp, argv[1]);

    strange(argv[1]);
    strange2(tmp);

    free(tmp);
    
    return 0;
}
