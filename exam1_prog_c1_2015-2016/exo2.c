#include <stdio.h>

void tri_lineaire_borne(int t[], int n)
{
    int occurence[100];
    int i, j, x, val;

    for (i = 0; i < 100; i++)
        occurence[i] = 0;

    for (i = 0; i < n; i++) {
        val = t[i];
        occurence[val] = occurence[val] + 1;
    }

    x = 0;

    for (i = 0; i < 100; i++) {
        val = occurence[i];

        for (j = 0; j < val; j++) {
            t[x] = i;
            x++;
        }
    }

    for (i = 0; i < n; i++)
        printf("%d ", t[i]);

    printf("\n");
}

int main(void)
{
    int t[15] = {1,7,3,5,1,3,7,3,5,3,2,1,4,6,9};
    tri_lineaire_borne(t, 15);

    return 0;
}
