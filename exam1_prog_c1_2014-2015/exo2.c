#include <stdio.h>

void print_array(int tab[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", tab[i]);

    printf("\n");
}

void miror_array(int tab[], int n)
{
    int tmp, i, j, middle;

    if (n < 2)
        return;

    j = 0;
    
    if (n % 2 == 0)
        middle = (n / 2) - 1;
    else
        middle = n / 2;

    for (i = n - 1; i > middle; i--) 
    {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
        j++;
    }
}

int main(int argc, char *argv[]) 
{
    int tab[] = {12,45,-3,18,5,7,-50, 54};

    print_array(tab, 8);
    miror_array(tab, 8);
    print_array(tab, 8);

    return 0;
}
