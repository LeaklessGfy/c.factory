/*
 * TP3 Exercice 5 - Maudit trie ! Enfin trie à bulle
 * @author Vincent Rasquier et google 
 * ESIPE IR 1
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Attribue des valeurs aléatoires à un tableau
 * Fait intéressant : tab est directement modifié, pas de copie de variable.
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
 * Le fameux trie
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
 * La fonction main !
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
