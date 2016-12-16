#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void     miroir_string(char **str)
{
    int  len, i;
    char *new_str;

    len = strlen(*str);
    new_str = (char *) malloc(sizeof(char) * (len + 1));
    len--;
    
    for (i = 0; i <= len; i++)
        new_str[i] = (*str)[len - i];

    *str = new_str;
}

int      main(int argc, char *argv[])
{
    char *t;

    if (argc > 1)
        t = argv[1];
    else
        t = "trace";

    printf("Former : %s\n", t);
    miroir_string(&t);
    printf("New : %s\n", t);

    return 0;
}
