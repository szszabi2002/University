// 20200331a

#include <stdio.h>
#include <stdlib.h>

void tomb_statisztika(int tomb[], int meret, int *min, int *max, double *atlag)
{
    *min = tomb[0];
    *max = tomb[0];
    int osszeg = tomb[0];

    for (int i = 1; i < meret; i++)
    {
        if (tomb[i] < *min)
        {
            *min = tomb[i];
        }
        if (tomb[i] > *max)
        {
            *max = tomb[i];
        }
        osszeg += tomb[i];
    }

    *atlag = (double)osszeg / meret;
}

int main()
{
    srand(42);
    int tomb[10];
    int meret = 10;

    int legkisebb, legnagyobb;
    double atlag;

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

    tomb_statisztika(tomb, meret, &legkisebb, &legnagyobb, &atlag);
    printf("Legkisebb elem: %d\n", legkisebb);
    printf("Legnagyobb elem: %d\n", legnagyobb);
    printf("Az elemek átlaga: %.1f\n", atlag);

    return 0;
}