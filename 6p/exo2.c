#include <stdio.h>
#include <stdlib.h>
#define N 3

void show_array(int *arr, int max)
{
    int i;
    
    for (i = 0; i < max; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

void permutations(int buffer[], int current, int max)
{
    int i;
    
    if (current > max)
    {
        show_array(buffer, max);
    } 
    else 
    {
        for (i = 0; i < max; i++)
        {   
            if (buffer[i] == 0)
            {
                buffer[i] = current;
                permutations(buffer, current + 1, max);
                buffer[i] = 0;
            }
        }
    }
}

int main(void)
{
    int buf[3];
    
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    
    permutations(buf, 1, 3);
    
    return 0;
}
