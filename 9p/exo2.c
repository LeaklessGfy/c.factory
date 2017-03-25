#include <stdlib.h>
#include <stdio.h>

void getNumber(int *pt)
{
    scanf("%d", pt);
}

char** create2dArray(int len1, int len2)
{
    return (char**) malloc(sizeof(char) * (len1 * len2));
}

void deallocate(char **arr)
{
    free(arr);
}

void printArray(char **arr, int len1, int len2)
{
    int i, j;
    char begin1, begin2;
    
    begin1 = 'a';
    
    for (i = 0; i < len1; i++)
    {
        if (begin1 > 122)
            begin1 = 'a';

        begin2 = begin1;
        for (j = 0; j < len2; j++)
        {
            if (begin2 > 122)
                begin2 = 'a';
            
            printf("%c", begin2);
            begin2++;
        }
        
        printf("\n");
        begin1++;
    }
}

int main(int argc, char *argv[])
{
    int len1, len2;
    char **arr;
    
    printf("Donnez deux dimensions entières : \n");
    getNumber(&len1);
    getNumber(&len2);
    
    arr = create2dArray(len1, len2);
    printArray(arr, len1, len2);
    
    deallocate(arr);
    
    return 0;
}
