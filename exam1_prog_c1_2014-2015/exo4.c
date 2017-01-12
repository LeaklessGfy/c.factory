#include <stdio.h>

int x = 0;
/* Ca affiche 16 
** Faire l'arbre. (Car on commence toujours à gauche).
** 31 appel (16 * 2 - 1)
*/
int strange(int a, int b)
{
    x = x+1;
    if (a >= b)
        return 1;

    return strange(a+1, b) + strange(a, b-1);
}

int main(int argc, char *argv[])
{
    printf("%d\n", strange(0,4));
    printf("%d\n", x);
    return 0;
}
