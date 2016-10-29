/*
 * TP3 Exercice 4 - trie dichotomique
 * @author Vincent Rasquier
 * ESIPE IR 1
 * commentaire inutile: je veux retourner coder sur 'go' please !
 */
#include <stdio.h>

/*
 * Une recherche dichotomique
 * list = chaine d'entier trié, min = la valeur minimum (que l'on veut traiter)
 * de la list. max = la valeur maximum. key = la valeur qu'on cherche.
 * mid = le milieu entre min et max !
 */
int binary_search(int list[], int min, int max, int key)
{
	int mid;

	if (min > max)
	{
		printf("Key not found\n");
		return -1;
	}

	mid = (min + max) / 2;

	if (list[mid] == key)
	{
		printf("Key found\n");
		return mid;
	}

	if (list[mid] > key)
		return binary_search(list, min, mid - 1, key);

	return binary_search(list, mid + 1, max, key);  		
}

/*
 * Dat definition de list ! Faute de norme !
 */
int main(void)
{
	int result;
	int list[16] = {1, 2, 3, 15, 18, 22, 24, 33, 36, 39, 52, 55, 64, 65, 80, 125};

	result = binary_search(list, 0, 15, 18);
	
	if (result != -1)
		printf("%d \n", result);

	return 0;
}
