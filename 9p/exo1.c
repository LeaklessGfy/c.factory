#include <stdlib.h>
#include <stdio.h>

int* allocate(int len)
{
    int *alloc;

    alloc = (int*) malloc(len * sizeof(int));

    if (!alloc)
        exit(1);

    return alloc;
}

void deallocate(int *arr)
{
    free(arr);
}

void insertToArray(int *arr, int len)
{
    int i;
    
    for (i = 0; i < len; i++)
        arr[i] = i + 1;
}

void printArray(int *arr, int len)
{
    int i;
    
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main(int argc, char *argv[])
{
    int len;
    int *arr;
    
    if (argc < 2)
        return 1;
    
    len = atoi(argv[1]);
    arr = allocate(len);
    
    insertToArray(arr, len);
    printArray(arr, len);
    deallocate(arr);
    
    return 0;
}
