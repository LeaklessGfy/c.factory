#include <stdio.h>

void affiche_nombre_romain(int n)
{
    int i, j, x, tmp, tmp2;
    int co[] = {100, 50, 10, 5, 1};
    char *col = "CLXVI";

    if (n < 1)
        return;

    x = 0;
    tmp = n;

    while (n > 0) 
    {
        tmp = tmp - co[x];

        if (tmp >= 0) {
            n = tmp;
            printf("%c", col[x]);
        } else {
            tmp2 = tmp + 1;

            if (tmp2 == 0) {
                printf("%c%c", col[4], col[x]);
                n = 0;
            }

            tmp = tmp + co[x];
            x++;
        }

        if (x > 5)
            x = 5;
    }

    printf("\n");
}

int main(void) 
{
    printf("100 = ");
    affiche_nombre_romain(100);
    
    printf("50 = ");
    affiche_nombre_romain(50);
    
    printf("10 = "); 
    affiche_nombre_romain(10);
    
    printf("5 = ");
    affiche_nombre_romain(5);
    
    printf("1 = ");
    affiche_nombre_romain(1);
    
    printf("8 = ");
    affiche_nombre_romain(8);

    printf("66 = ");
    affiche_nombre_romain(66);

    printf("4 = ");
    affiche_nombre_romain(4);

    return 0;
}
