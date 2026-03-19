#include <stdio.h>

int get_min(int n, int tomb[])
{
    int min = tomb[0];
    for (int i = 1; i < n; i++)
    {
        if (tomb[i] < min)
        {
            min = tomb[i];
        }
    }
    return min;
}

int get_max(int n, int tomb[])
{
    int max = tomb[0];
    for (int i = 1; i < n; i++)
    {
        if (tomb[i] > max)
        {
            max = tomb[i];
        }
    }
    return max;
}

int main()
{
    int szamok[] = {5, 8, 2, 10, 3, -1, 7};
    int n = 7;

    int legkisebb = get_min(n, szamok);
    int legnagyobb = get_max(n, szamok);

    printf("A tömb elemei: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", szamok[i]);
    }
    printf("\n");

    printf("A legkisebb elem: %d\n", legkisebb);
    printf("A legnagyobb elem: %d\n", legnagyobb);

    return 0;
}
