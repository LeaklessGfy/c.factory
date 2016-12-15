#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void exo_1(void)
{
    int i, result;
    int hundred, tens, unit;
    
    hundred = tens = unit = 0;
    
    for (i = 0; i <= 500; i++)
    {
        if (i < 10)
            unit = i;
        else if (i < 100)
        {
            unit = i / 10;
            tens = i % 10;
        }
        else
        {
            hundred = i / 100;
            tens = (i / 10) % 10;
            unit = (i % 100) % 10;
        }
        
        hundred = (int) pow(hundred, 3);
        tens = (int) pow(tens, 3);
        unit = (int) pow(unit, 3);

        result = hundred + tens + unit;

        if (result == i)
            printf("%d \n", i);
    }
}

float c_2(int n)
{
    int   i;
    float result, one;
    
    one = result = 1;
    
    for (i = 2; i <= n; i++)
        result = result + (float)(one / i);
    
    return result;
}

double c_2_double(int n)
{
    int    i;
    double result, one;
    
    one = result = 1;
    
    for (i = 2; i <= n; i++)
        result = result + (double)(one / i);
    
    return result;
}

void exo_2(void)
{
    int   n;
    float former, result;
    
    result = 0;
    former = 1;
    n = 1000;
    
    while (result != former)
    {
        former = result;
        result = c_2(n);
        n--;
        
        if (n % 1000 == 0)
            printf("%d : %f\n", n, result);
    }
}

void exo_2_bis(void)
{
    int    n;
    double former, result;
    
    result = 0;
    former = 1;
    n = 1000;
    
    while (result != former)
    {
        former = result;
        result = c_2_double(n);
        n--;

        if (n % 1000 == 0)
            printf("%d : %lf\n", n, result);
    }
}

void miroir_string(char **str)
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

void print_robot(char *first_line, char *second_line, char *third_line, int l)
{
    int  i;
    char *robot, *space;

    space = (char *) malloc(sizeof(char) * l);
    for (i = 0; i < l; i++)
    {
        space[i] = ' ';
    }

    robot = (char *) malloc(sizeof(char) * ((l * 11) + 319));

    strcat(robot, space);
    strcat(robot, "               / \n");
    strcat(robot, space);
    strcat(robot, "              /      \n");
    strcat(robot, space);
    strcat(robot, "      ,     ,        \n");
    strcat(robot, space);
    strcat(robot, "     (\\____/)       \n");
    strcat(robot, space);
    strcat(robot, "      (_oo_)         \n");
    strcat(robot, space);
    strcat(robot, "        (O)          \n");
    strcat(robot, space);
    strcat(robot, "      __/\\__    \\) \n");
    strcat(robot, space);
    strcat(robot, "   []/______\\[] /   \n");
    strcat(robot, space);
    strcat(robot, "   / \\______/ \\/   \n");
    strcat(robot, space);
    strcat(robot, "  /    /__\\         \n");
    strcat(robot, space);
    strcat(robot, " (\\   /____\\       \n");

    printf("%s\n", first_line);
    printf("%s\n", second_line);
    printf("%s\n", third_line);
    printf("%s", robot);

    free(space);
    free(robot);
}

void robot_say(char *str, int len)
{
    int  len_space, additional_space, i;
    char *space, *first_line, *second_line, *third_line;
    
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

    print_robot(first_line, second_line, third_line, additional_space);

    free(space);
    free(first_line);
    free(second_line);
    free(third_line);
}
    
int main(int argc, char *argv[])
{
    char *t;

    if (argc > 1)
        t = argv[1];
    else
        t = "Robot Rock";

    printf("# EXO 1\n");
    exo_1();
    printf("\n");
    
    printf("# EXO 2 - float\n");
    //exo_2();
    
    printf("# EXO 2 - double\n");
    //exo_2_bis();
    printf("\n");

    printf("# EXO 3 - mirror string\n");
    printf("Former : %s\n", t);
    miroir_string(&t);
    printf("New : %s\n\n", t);
    
    printf("# EXO 4\n");
    miroir_string(&t);
    robot_say(t, strlen(t));
    
    return 0;
}
