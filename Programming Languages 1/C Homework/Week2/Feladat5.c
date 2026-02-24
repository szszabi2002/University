#include <stdio.h>

int main()
{
    printf("ASCII táblázat 32-126: \n");
    for (int i = 32; i <= 126; i++) {
        printf("%d: %c\n", i, i);
    }
    printf("Angol ábécé nagybetűihez tartozó ASCII értékek összege: ");
    int osszeg = 0;
    for (int i = 65; i <= 90; i++) {
        osszeg += i;
    }
    printf("%d\n", osszeg);
    return 0;
}