#include <stdio.h>

int main()
{
    int osszeg = 0;
    for (int i = 1; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            osszeg += i;
        }
    }
    printf("Az 1000-nél kisebb számok összege, melyek 3-nak vagy 5-nek a többszörösei: %d\n", osszeg);
    return 0;
}