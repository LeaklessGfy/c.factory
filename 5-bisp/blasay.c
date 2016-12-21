#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
** Print robot on screen. Additional space possible to center robot
** @author Vincent Rasquier
*/
void     print_robot(int l)
{
    int  i;
    char *space;

    space = (char *) malloc(sizeof(char) * l);
    for (i = 0; i < l; i++)
    {
        space[i] = ' ';
    }

    printf("%s               /     \n", space);
    printf("%s              /      \n", space);
    printf("%s      ,     ,        \n", space);
    printf("%s     (\\____/)       \n", space);
    printf("%s      (_oo_)         \n", space);
    printf("%s        (O)          \n", space);
    printf("%s      __/\\__    \\) \n", space);
    printf("%s   []/______\\[] /   \n", space);
    printf("%s   / \\______/ \\/   \n", space);
    printf("%s  /    /__\\         \n", space);
    printf("%s (\\   /____\\       \n", space);
}

/*
** Construct bubble with right space and print robot
** @author Vincent Rasquier
*/
void     robot_say(char *str)
{
    int  len, len_space, additional_space, i;
    char *space, *first_line, *second_line, *third_line;

    len = strlen(str);
    
    len_space = 14 - (len / 2);
    additional_space = 0;

    if (len_space < 0) {
        additional_space = ~len_space + 3;
        len_space = 0;
    }
    
    space = (char *) malloc(sizeof(char) * len_space);
    for (i = 0; i < len_space; i++)
    {
        space[i] = ' ';
    }

    second_line = (char *) malloc(sizeof(char) * (len + len_space + 5));
    strcat(second_line, space);
    strcat(second_line, "< ");
    strcat(second_line, str);
    strcat(second_line, " >");

    first_line = (char *) malloc(sizeof(char) * (len + len_space + 4));
    third_line = (char *) malloc(sizeof(char) * (len + len_space + 4));
    strcat(first_line, space);
    strcat(first_line, " _");
    strcat(third_line, space);
    strcat(third_line, " -");

    for (i = 0; i <= len; i++)
    {
        strcat(first_line, "_");
        strcat(third_line, "-");
    }

    printf("%s\n", first_line);
    printf("%s\n", second_line);
    printf("%s\n", third_line);
    print_robot(additional_space);

    free(space);
    free(first_line);
    free(second_line);
    free(third_line);
}

/*
** Main
*/
int      main(int argc, char *argv[])
{
    char *t;

    if (argc > 1)
        t = argv[1];
    else
        t = "Robot Rock";

    robot_say(t);

    return 0;
}
