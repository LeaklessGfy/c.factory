#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LENGTH 200000000

unsigned long int t[LENGTH];

void init_array(void)
{
	int i;

	for (i = 0; i < LENGTH; i++)
		t[i] = -1;

	t[1] = 0;
}

unsigned long int syracuse_iter(unsigned long int init)
{
	unsigned long int size;

	size = 0;

	while (init != 1)
	{
		if (init % 2)
			init = 3 * init + 1;
		else
			init = init / 2;

		size = size + 1;		
	}

	return size;
}

int syracuse_suivant(n)
{
	if (n % 2)
		return 3 * n + 1;

	return n / 2;
}

unsigned long int syracuse_rec(unsigned long int init)
{
	unsigned long int size;

	size = 0;

	if (init > LENGTH)
		return 1 + syracuse_rec(syracuse_suivant(init));

	if (t[init] != -1)
		return t[init];

	t[init] = 1 + syracuse_rec(syracuse_suivant(init));

	return size;
}

int main(int argc, char *argv[])
{
	unsigned long int i, len, tmp;
	char *mode;

	if (argc < 2)
		return 1;

	mode = argv[1];
	len = tmp = 0;

	if (strcmp(mode, "iter") == 0) {
		printf("Iter\n");
	
		for (i = 0; i < LENGTH; i++) {
			tmp = syracuse_iter(i);

			if (tmp > len)
				len = tmp;
		}
	} else {
		printf("Rec\n");
		init_array();

		for (i = 0; i < LENGTH; i++)
		{
			len = syracuse_rec(i);
		}
	}

	for (i = 0; i < LENGTH; i++) {
		if (t[i] > len && t[i] != -1)
			len = t[i];
	}

	printf("MAX FLY : %d\n", len);

	return 0;
}

