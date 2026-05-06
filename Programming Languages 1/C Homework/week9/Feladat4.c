// 20200416g

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int n, int tomb[])
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = temp;
    }
}

void kiir(int n, int tomb[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tomb[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int szamok[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(szamok) / sizeof(szamok[0]);

    printf("Eredeti tomb: ");
    kiir(n, szamok);
    shuffle(n, szamok);
    printf("Elso keveres: ");
    kiir(n, szamok);
    shuffle(n, szamok);
    printf("Masodik keveres: ");
    kiir(n, szamok);

    return 0;
}