#ifndef _TP5_
#define _TP5_

int* allocate_integer_array(int size);
void free_integer_array(int* tab);

/*
** Exo 1
*/
/* Return the int* array size give in parameter */
int  array_size(int *array);

/* Print the content of int* array give in parameter */
void print_array(int *array);

/* Check if int* first and int* second, give in parameters, are equal. */
int  are_arrays_equal(int *first, int *second);

/* Return a copy of int* array give in parameter */
int* copy_array(int *array);

/*
** Exo 2
*/
/* Return an int* array fill by the user */
int* fill_array(void);

/* Return int* array create with random values */
int* random_array(int size, int max_entry);

/* Return int* array wich is the concatenation between first and second */
int* concat_array(int *first, int *second);

/*
** Exo 3
*/
/* Return sorted int* array create with int* first and int* second */
int* merge_sorted_arrays(int *first, int *second);

/* Splits int* array into pointer first and pointer second */
void split_arrays(int *array, int **first, int **second);

/* Return an sorted int array of int* array give in parameter */
int* merge_sort(int *array);

#endif
