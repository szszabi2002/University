#include <stdio.h>

int main()
{
    printf("Kérem adjon meg egy számot és felsorolom a számokat -> használatával: ");
    int szam;
    scanf("%d", &szam);
    for (int i = 1; i <= szam; i++)
    {
        printf("%d", i);
        if (i < szam)
        {
            printf(" -> ");
        }
    }
    printf("\n");
    return 0;
}