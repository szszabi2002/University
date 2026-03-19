#include <stdio.h>

int contains(int n, int tomb[], int ertek)
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] == ertek)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int szamok[] = {5, 8, 2, 10, 3, -1, 7};
    int n = 7;
    int keresett = 10;

    if (contains(n, szamok, keresett))
    {
        printf("A tömb tartalmazza a %d értéket\n", keresett);
    }
    else
    {
        printf("A tömb NEM tartalmazza a %d értéket\n", keresett);
    }

    keresett = 42;
    if (contains(n, szamok, keresett))
    {
        printf("A tömb tartalmazza a %d értéket\n", keresett);
    }
    else
    {
        printf("A tömb NEM tartalmazza a %d értéket\n", keresett);
    }

    return 0;
}
