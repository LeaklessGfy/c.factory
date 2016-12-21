#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void       exo_1(void)
{
    int    i, result;
    int    hundred, tens, unit;
    
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

float      c_2(int n)
{
    int    i;
    float  result, one;
    
    one = result = 1;
    
    for (i = 2; i <= n; i++)
        result = result + (float)(one / i);
    
    return result;
}

double     c_2_double(int n)
{
    int    i;
    double result, one;
    
    one = result = 1;
    
    for (i = 2; i <= n; i++)
        result = result + (double)(one / i);
    
    return result;
}

void       exo_2(void)
{
    int    n;
    float  former, result;
    
    result = 0;
    former = 1;
    n = 1000;
    
    while (result != former)
    {
        former = result;
        result = c_2(n);
        
        if (n % 1000 == 0)
            printf("%d : %f\n", n, result);

        n++;
    }
}

void       exo_2_bis(void)
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

        if (n % 1000 == 0)
            printf("%d : %lf\n", n, result);

        n++;
    }
}
    
int        main(int argc, char *argv[])
{
    printf("# EXO 1\n");
    exo_1();
    printf("\n");
    
    printf("# EXO 2 - float\n");
    exo_2();
    printf("\n");
    
    printf("# EXO 2 - double\n");
    exo_2_bis();
    printf("\n");

    return 0;
}
