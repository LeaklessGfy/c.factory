/*
 * TP3 Exercice 1 - Calcul de puissance
 * @author Vincent Rasquier
 * ESIPE IR 1
 */
#include <stdio.h>

/*
 * Calcul une puissance avec une boucle. a ^ n
 */
int puissance(int a, int n)
{
	int result;
	
	result = 1;

	while (n != 0)
	{
		result = result * a;
		n--;
	}

	return result;
}

/*
 * Calcul une puissance de manière recursive. a ^ n
 */
int puissance_recursive(int a, int n)
{
	if (n < 1)
		return 1;

	if (n == 1)
		return a;

	n--;

	return a * puissance_recursive(a, n);
}

/*
 * Appel des deux fonctions dans me main.
 * p = entier temporaire pour stoquer un result
 */
int main(void)
{
	int p;

	p = puissance(2,6);
	printf("Puissance : 2^6 = %d\n", p);

	p = puissance_recursive(2, 10);
	printf("Puissance Recursive : 2^10 = %d\n", p);

	return 0;
}
