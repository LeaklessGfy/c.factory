/*
 * TP3 Exercice 3 - Base26 <=> Int converter
 * @author Vincent Rasquier and Google (stradd)
 * ESIPE IR 1
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Check if char c is lower between a and z include.
 */
int is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;

	return 0;
}

/*
 * Check if char c is numeric, between 0 and 9 include.
 */
int is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return 1;

	return 0;
}

/*
 * Convert char * to int. tmp = numeric representation of a char (a = 0)
 */
int base26_to_int(char *str)
{
	int result, current, tmp;
	int len;

	result = 0;
	current = 1;
	len = strlen(str);

	while (len > 0)
	{
		tmp = str[len-1] - 97;
		result = result + (tmp * current);
		current = current * 26;
		len--;
	}

	return result;
}

/*
 * Bloody concatenation. (Thanks google by the way)
 * a + b was too easy 'nest-ce pas ?'. Should I free ret ? why I speak english ?
 * This function makin' me crazy
 */
char* stradd(char *a, char *b)
{
	size_t len;
	char   *ret;

	len = 1 + strlen(b);
	ret = (char*)malloc(len * sizeof(char) + 1);
	*ret = '\0';

	return strcat(strcat(ret, a), b);
}

/*
 * Convert a str (wich is an int ...) to base 26
 * b10 = numeric representation of str
 */
char* int_to_b26(char *str)
{
	int  b10, rest;
	char *result;
	char digit[2];

	b10 = atoi(str);
	result = "";
	digit[1] = '\0';

	while (b10 > 0)
	{
		rest = b10 % 26;
		digit[0] = (char)(rest + 97);

		result = stradd(digit, result);

		b10 = (b10 - rest) / 26;
	}

	return result;
}

/*
 * Main
 */
int main(int argc, char *argv[])
{
	char *str, *b26;
	int  i, len, b10;
	int  lower, integer;

	str     = argv[1];
	lower   = 1;
	integer = 1;
	len     = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (lower)
			lower = is_lower(str[i]);

		if (integer)
			integer = is_numeric(str[i]);
	}

	if (lower)
	{
		b10 = base26_to_int(str);
		printf("(%s)base26 = (%d)base10\n", str, b10);
	}
	else if (integer)
	{
		b26 = int_to_b26(str);
		printf("(%d)base10 = (%s)base26\n", atoi(str), b26);
	}
	else
	{
		return 1;
	}

	return 0;
}
