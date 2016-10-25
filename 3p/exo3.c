#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;

	return 0;
}

int is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return 1;

	return 0;
}

int base26_to_int(char *str)
{
	int result, current, tmp;
	int len;

	result = 0;
	current = 1;
	len = strlen(str) - 1;

	for (len; len+1 > 0; len--)
	{
		tmp = str[len] - 97;
		result = result + (tmp * current);
		current = current * 26;
	}

	return result;
}

char* stradd(char *a, char *b)
{
	size_t len;
	char   *ret;

	len = 1 + strlen(b);
	ret = (char*)malloc(len * sizeof(char) + 1);
	*ret = '\0';

	return strcat(strcat(ret, a), b);
}

char* int_to_b26(char *str)
{
	int  b10;
	int  rest, tmp;
	char *result, *bak;
	char digit[2];

	b10 = atoi(str);
	result = "";

	while (b10 > 0)
	{
		rest = b10 % 26;

		digit[0] = (char)(rest + 97);
		digit[1] = '\0';

		result = stradd(digit, result);

		b10 = (b10 - rest) / 26;
	}

	return result;
}

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
