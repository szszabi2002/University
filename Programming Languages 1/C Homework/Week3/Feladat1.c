#include <stdio.h>

int main()
{
    printf("Magassag: ");
    int m;
    scanf("%d", &m);
    printf("\n");

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= m - i; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");
        
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}