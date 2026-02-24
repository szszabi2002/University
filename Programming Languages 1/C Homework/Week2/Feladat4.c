#include <stdio.h>

int main()
{
    printf("Kérem adjon meg egy számot és kiírom visszafelé páratlan számokat: ");
    int szam;
    scanf("%d", &szam);
    for (int i = szam; i >= 1; i--) {
        if (i % 2 == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}