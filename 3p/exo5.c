/*
 * TP3 Exercice 5 - Bubble tea ... (what do we say about funny comment again ?) sort
 * @author Vincent Rasquier et google 
 * ESIPE IR 1
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Generate a random value for every position of tab (0 to size - 1)
 */
void generate_random(int tab[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		tab[i] = rand() % 70;
		printf("%d ", tab[i]);
	}

	printf("\n");
}

/*
 * Sort the tab in 'croissant' order
 */
void bubble_sort(int tab[], int size)
{
	int tmp; 
	int i;
	int x;

	for (i = 0; i < size; i++)
	{
		for (x = i; x < size; x++)
		{
			if (tab[i] > tab[x])
			{
				tmp = tab[i];
				tab[i] = tab[x];
				tab[x] = tmp;
			}
		}
	}
}

/*
 * fmt.Println(tab)
 */
void print_arr(int tab[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}

	printf("\n");
}

/*
 * The organizator (good night ! thanks)
 */
int main(void)
{
	int list[22];
	int size;

	size = 22;

	generate_random(list, size);
	bubble_sort(list, size);
	print_arr(list, size);

	return 0;
}
