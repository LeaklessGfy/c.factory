#include <stdio.h>
#include <string.h>
#include "tp5.h"

void test_1(void)
{
    int *arr, *arr2, *arr3;

    arr = allocate_integer_array(5);
    arr[0] = 7;
    arr[1] = 8;
    arr[2] = 6;
    arr[3] = 5;
    arr[4] = -1;

    arr2 = allocate_integer_array(6);
    arr2[5] = -1;

    printf("Array 1 size: %d\n", array_size(arr));
    printf("Array 2 size: %d\n", array_size(arr2));

    printf("\nArray 1: \n");
    print_array(arr);

    printf("Array 2: \n");
    print_array(arr2);

    printf("\nAre they equal (Array 1, Array 2) ? Yes => 1 No => 0 \n");
    printf("%d\n", are_arrays_equal(arr, arr2));

    arr3 = copy_array(arr);
    printf("\nCopy Array 1 to Array 3\n");
    printf("Array 3: \n");
    print_array(arr3);

    printf("\nAre they equal (Array 1, Array 3) ? Yes => 1 No => 0 \n");
    printf("%d\n", are_arrays_equal(arr, arr3));

    free_integer_array(arr);
    free_integer_array(arr2);
    free_integer_array(arr3);
}

void test_2(void)
{
    int *arr, *arr2, *arr3;

    arr = fill_array();

    printf("Array 1: \n");
    print_array(arr);

    arr2 = random_array(6, 100);

    printf("Array 2: \n");
    print_array(arr2);

    arr3 = concat_array(arr, arr2);

    printf("Array 3: \n");
    print_array(arr3);

    free_integer_array(arr);
    free_integer_array(arr2);
    free_integer_array(arr3);
}

void test_3(void)
{
    int *arr, *sorted_arr;

    arr = random_array(20, 100);

    printf("1/ Now a random array of length 20 whose entries are lower than 100 :\n");
    print_array(arr);

    printf("\n2/ Using a merge sort, we get :\n");
    sorted_arr = merge_sort(arr);

    printf("\n3/ Here is the sorted array :\n");
    print_array(sorted_arr);

    free_integer_array(arr);
    free_integer_array(sorted_arr);
}

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        test_3();
    }
    else if (strcmp(argv[1], "1") == 0)
    {
        test_1();
    }
    else if (strcmp(argv[1], "2") == 0)
    {
        test_2();
    }

    return 0;
}
