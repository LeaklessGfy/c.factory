/*
 * TP3 Exercice 4 - Binary Search
 * @author Vincent Rasquier
 * ESIPE IR 1
 * (Please let me return on Go ... Funny comment will be prohibithed after this function)
 */
#include <stdio.h>

/*
 * Une recherche dichotomique
 * list = chaine d'entier trié, min = la valeur minimum (que l'on veut traiter)
 * de la list. max = la valeur maximum. key = la valeur qu'on cherche.
 * mid = le milieu entre min et max ! (c'était dur à expliquer en anglais)
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
 * List init make the ligne 45 too large ... -1 for norme
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
