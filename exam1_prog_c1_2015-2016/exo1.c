#include <stdio.h>

int concat(char *dest, char *s1, char *s2)
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		dest[i] = s1[i];

	for (j = 0; s2[j] != '\0'; j++)
		dest[i + j] = s2[j];

	dest[i + j] = '\0';

	return i + j;
}

int main(int argc, char *argv[])
{
	int r;
	char dest[11];
	char *s1 = "Hello ";
	char *s2 = "Toto";

	r = concat(dest, s1, s2);
	printf("Number : %d \n", r);
	printf("String : %s \n", dest);

	return 0;
}
