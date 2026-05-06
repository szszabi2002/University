// 20200407a

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int min;
    int max;
    double atlag;
} Statisztika;

Statisztika tomb_statisztika(int tomb[], int meret)
{
    Statisztika eredmeny;

    eredmeny.min = tomb[0];
    eredmeny.max = tomb[0];
    int osszeg = tomb[0];

    for (int i = 1; i < meret; i++)
    {
        if (tomb[i] < eredmeny.min)
        {
            eredmeny.min = tomb[i];
        }
        if (tomb[i] > eredmeny.max)
        {
            eredmeny.max = tomb[i];
        }
        osszeg += tomb[i];
    }

    eredmeny.atlag = (double)osszeg / meret;

    return eredmeny;
}

int main()
{
    srand(42);

    int tomb[10];
    int meret = 10;

    for (int i = 0; i < meret; i++)
    {
        tomb[i] = (rand() % 90) + 10;
    }

    printf("A tömb elemei: ");
    for (int i = 0; i < meret; i++)
    {
        printf("%d", tomb[i]);
        if (i < meret - 1)
        {
            printf(", ");
        }
    }
    printf("\n");

    Statisztika eredmeny = tomb_statisztika(tomb, meret);
    printf("Legkisebb elem: %d\n", eredmeny.min);
    printf("Legnagyobb elem: %d\n", eredmeny.max);
    printf("Az elemek átlaga: %.1f\n", eredmeny.atlag);

    return 0;
}