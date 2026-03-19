#include <stdio.h>

int is_even(int n)
{
    return n % 2 == 0;
}

int is_odd(int n)
{
    // return n % 2 != 0;
    // vagy
    return !is_even(n);
}

int main()
{
    int szam;
    printf("Adjon meg egy egész számot: ");
    scanf("%d", &szam);

    if (is_even(szam))
    {
        printf("A szám páros.\n");
    }
    if (is_odd(szam))
    {
        printf("A szám páratlan.\n");
    }

    return 0;
}
