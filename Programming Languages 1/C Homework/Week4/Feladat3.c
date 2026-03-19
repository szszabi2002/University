#include <stdio.h>

int is_sorted(int n, int tomb[])
{
    if (n <= 1)
    {
        return 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (tomb[i] > tomb[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int tomb1[] = {1, 2, 4, 7, 9};
    int n1 = 5;

    int tomb2[] = {3, 1, 4, 1, 5};
    int n2 = 5;

    int tomb3[1] = {0};
    int n3 = 0;

    if (is_sorted(n1, tomb1))
    {
        printf("Az 1. tömb rendezett.\n");
    }
    else
    {
        printf("Az 1. tömb NEM rendezett.\n");
    }

    if (is_sorted(n2, tomb2))
    {
        printf("A 2. tömb rendezett.\n");
    }
    else
    {
        printf("A 2. tömb NEM rendezett.\n");
    }

    if (is_sorted(n3, tomb3))
    {
        printf("A 3. (üres) tömb rendezett.\n");
    }
    else
    {
        printf("A 3. (üres) tömb NEM rendezett.\n");
    }

    return 0;
}
