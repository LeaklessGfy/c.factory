#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp5.h"

/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size)
{
    int* new_tab;

    new_tab = (int*)malloc((size+1)*sizeof(int));

    if (new_tab == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab)
{
    free(tab);
}

/*
** Return the int* array size give in parameter
** @author Vincent RASQUIER
*/
int array_size(int *array)
{
    int i;

    i = 0;

    while (array[i] != -1)
    {
        i++;
    }

    return i;
}

/*
** Print the content of int* array give in parameter
** @author Vincent RASQUIER
*/
void print_array(int *array)
{
    int len, i;

    len = array_size(array);

    for (i = 0; i < len; i++)
    {
        printf("%d", array[i]);

        if (i + 1 < len)
            printf(" - ");
    }

    printf("\n");
}

/*
** Check if int* first and int* second, give in parameters, are equal. 
** Return 1 if it's true, 0 if it's false
** @author Vincent RASQUIER
*/
int are_arrays_equal(int *first, int *second)
{
    int len1, len2, i;

    len1 = array_size(first);
    len2 = array_size(second);

    if (len1 != len2)
        return 0;

    for (i = 0; i < len1; i++)
    {
        if (first[i] != second[i])
            return 0;
    }

    return 1;
}

/*
** Return a copy of int* array give in parameter
** @author Vincent RASQUIER
*/
int* copy_array(int *array)
{
    int len, i;
    int *new_array;

    len = array_size(array);
    new_array = allocate_integer_array(len + 1);

    for (i = 0; i <= len; i++)
    {
        new_array[i] = array[i];
    }

    return new_array;
}

/*
** Return an int* array fill by the user
** @author Vincent RASQUIER
*/
int* fill_array(void)
{
    int len, tmp, i;
    int *arr;
    
    len = 0;

    printf("Longueur du tableau: ");
    scanf("%d", &len);

    arr = allocate_integer_array(len + 1);

    for (i = 0; i < len; i++)
    {
        printf("Entier dans tableau à la position %d: ", i);
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    arr[len] = -1;

    return arr;
}

/*
** Return int* array create with random values
** @author Vincent RASQUIER
*/
int* random_array(int size, int max_entry)
{
    int i;
    int *arr;

    arr = allocate_integer_array(size + 1);
    srand(time(NULL));

    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % max_entry;
    }

    arr[size] = -1;

    return arr;
}

/*
** Return int* array wich is the concatenation between
** int* first and int* second 
** @author Vincent RASQUIER
*/
int* concat_array(int *first, int *second)
{
    int fullLen, len1, len2, i;
    int *arr;

    len1 = array_size(first);
    len2 = array_size(second);
    fullLen = len1 + len2;

    arr = allocate_integer_array(fullLen+1);

    for (i = 0; i < len1; i++)
    {
        arr[i] = first[i];
    }

    for (i = 0; i < len2; i++)
    {
        arr[i + len1] = second[i];
    }

    arr[fullLen] = -1;

    return arr;
}

/*
** Return sorted int* array create with int* first and int* second
** which are two sorted array
** @author Vincent RASQUIER
*/
int* merge_sorted_arrays(int *first, int *second)
{
    int len1, len2, i1, i2;
    int *arr;
    int tmp[2];

    arr = allocate_integer_array(0);
    arr[0] = tmp[1] = -1;
    i1 = i2 = 0;

    printf("- Merge the two following ones :\n");
    print_array(first);
    print_array(second);

    len1 = array_size(first);
    len2 = array_size(second);

    while (i1 < len1 && i2 < len2)
    {
        if (first[i1] <= second[i2])
        {
            tmp[0] = first[i1];
            arr = concat_array(arr, tmp);
            i1++;
        } 
        else
        {
            tmp[0] = second[i2];
            arr = concat_array(arr, tmp);
            i2++;
        }
    }

    while (i1 < len1)
    {
        tmp[0] = first[i1];
        arr = concat_array(arr, tmp);
        i1++;
    }

    while (i2 < len2)
    {
        tmp[0] = second[i2];
        arr = concat_array(arr, tmp);
        i2++;
    }

    print_array(arr);

    return arr;
}

/*
** Splits int* array into pointer first and pointer second
** @author Vincent RASQUIER
*/
void split_arrays(int *array, int **first, int **second)
{
    int len, middle, rest, i;
    int *arr1, *arr2;

    printf("- Split array in two part :\n");
    print_array(array);

    len = array_size(array);
    middle = len / 2;
    rest = len - middle;

    arr1 = allocate_integer_array(middle + 1);
    arr2 = allocate_integer_array(rest + 1);

    for (i = 0; i < middle; i++)
    {
        arr1[i] = array[i]; 
    }
    arr1[middle] = -1;

    for (i = 0; i < rest; i++)
    {
        arr2[i] = array[i + middle];
    }
    arr2[rest] = -1;

    print_array(arr1);
    print_array(arr2);

    *first = arr1;
    *second = arr2;
}

/*
** Return an sorted int array of int* array give in parameter
** @author Vincent RASQUIER
*/
int* merge_sort(int *array)
{
    int *new_arr, *arr1, *arr2;

    new_arr = copy_array(array);

    if (array_size(new_arr) < 2)
        return new_arr;

    split_arrays(new_arr, &arr1, &arr2);
    new_arr = merge_sorted_arrays(merge_sort(arr1), merge_sort(arr2));

    free_integer_array(arr1);
    free_integer_array(arr2);

    return new_arr;
}
