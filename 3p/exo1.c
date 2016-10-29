/*
 * TP3 Exercice 1 - Calculate power
 * @author Vincent Rasquier
 * ESIPE IR 1
 */
#include <stdio.h>

/*
 * Calculate power with loop. int a ^ int n
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
 * Calculate power with recursion. int a ^ int n
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
 * Call puissance for 2 ^ 6 and puissance_recursive for 2 ^ 10
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
