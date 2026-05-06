// Hozzon létre a main() fv.-ben egy 6 x 6 méretű mátrixot. Egy eljárás segítségével írassa ki a mellékátló elemeit

#include <stdio.h>

void mellekatlo_kiir(int n, int matrix[n][n])
{
    printf("A mellekatlo elemei:\n");
    for (int i = 0; i < n; i++)
    {
        // A mellekatlo oszlopindexe: (meret - 1 - aktualis_sor)
        printf("%d ", matrix[i][n - 1 - i]);
    }
    printf("\n");
}

int main()
{
    int m[6][6];
    int szam = 1;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            m[i][j] = szam++;
        }
    }

    mellekatlo_kiir(6, m);

    return 0;
}