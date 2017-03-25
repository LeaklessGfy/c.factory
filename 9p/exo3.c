#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** allocate(int len, char *arr[])
{
    char **n_arr;
    int i;
    
    n_arr = (char**) malloc(sizeof(char*) * len);

    if (!n_arr)
        exit(1);
    
    for (i = 0; i < len; i++)
        n_arr[i] = (char*) malloc(sizeof(char) * (strlen(arr[i]) + 1));
    
    return n_arr;
}

void deallocate(int len, char *arr[])
{
    int i;
    
    for (i = 0; i < len; i++)
        free(arr[i]);
    
    free(arr);
}

void copy(int len, char *src[], char *dst[])
{
    int i;
    
    for (i = 0; i < len; i++)
        strcpy(dst[i], src[i]);
}

void printArray(int len, char *str[])
{
    int i;
    
    for (i = 0; i < len; i++)
        printf("%s\n", str[i]);
}

int main(int argc, char *argv[])
{
    char **arr;
    
    arr = allocate(argc, argv);
    copy(argc, argv, arr);
    printArray(argc, arr);
    deallocate(argc, arr);
}
