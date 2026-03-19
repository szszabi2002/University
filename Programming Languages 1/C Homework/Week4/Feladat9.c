#include <stdio.h>

void abszolut_ertekre_valt(int n, int tomb[])
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] < 0)
        {
            tomb[i] = -tomb[i];
        }
    }
}

void print_tomb(int n, int tomb[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", tomb[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    int szamok[] = {12, -5, 0, -8, 3, -10, 7};
    int n = 7;

    printf("Eredeti tömb: ");
    print_tomb(n, szamok);

    abszolut_ertekre_valt(n, szamok);

    printf("Módosított tömb: ");
    print_tomb(n, szamok);

    return 0;
}
