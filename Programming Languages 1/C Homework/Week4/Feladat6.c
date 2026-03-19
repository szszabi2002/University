#include <stdio.h>

int index_of(int n, int tomb[], int ertek)
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] == ertek)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int szamok[] = {5, 8, 2, 10, 3, -1, 7};
    int n = 7;
    int keresett = 10;

    int pozicio = index_of(n, szamok, keresett);

    if (pozicio != -1)
    {
        printf("A %d érték a %d. indexen található\n", keresett, pozicio);
    }
    else
    {
        printf("A %d érték nem található a tömbben\n", keresett);
    }

    keresett = 42;
    pozicio = index_of(n, szamok, keresett);

    if (pozicio != -1)
    {
        printf("A %d érték a % d. indexen található\n", keresett, pozicio);
    }
    else
    {
        printf("A %d érték nem található a tömbben\n", keresett);
    }

    return 0;
}
