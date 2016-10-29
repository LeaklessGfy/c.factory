/*
 * TP3 Exercice 2 - Compteur dans une chaine de caractère
 * @author Vincent Rasquier
 * ESIPE IR 1
 */
#include <stdio.h>
#include <string.h>

/*
 * La fonction la plus moche du monde !
 */
void wc(void)
{
	char str[240];
	int i, len;
	int counter_char, counter_word, counter_ligne;

	counter_char = 0;
	counter_word = 1;
	counter_ligne = 0;

	if (fgets(str, 240, stdin) == NULL)
		return;	

	len = strlen(str);

	if (len < 1)
		return;

	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			counter_word++;

		if (str[i] == '\n')
			counter_ligne++;

		counter_char++;
	}

	printf("Char : %d\n", counter_char);
	printf("Word : %d\n", counter_word);
	printf("Ligne: %d\n", counter_ligne);
}

/*
 * Humiliation de la fonction main here !
 */
int main(void)
{
	wc();

	return 0;
}
