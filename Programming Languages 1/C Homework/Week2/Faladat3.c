#include <stdio.h>

int main()
{
    printf("Kérem adjon meg egy számot és kiírom a 4-gyel osztható számokat: ");
    int szam;
    scanf("%d", &szam);
    for (int i = 1; i <= szam; i++) {
        if (i % 4 == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}