#include <stdio.h>
#include <stdlib.h>

int main() {
    int db;
    
    printf("Hány db számot szeretnél bevinni?\n");
    scanf("%d", &db);

    int eredeti[db];
    int masolat[db];

    for (int i = 0; i < db; i++) {
        printf("%d. szám: ", i + 1);
        scanf("%d", &eredeti[i]);
    }

    for (int i = 0; i < db; i++) {
        masolat[i] = abs(eredeti[i]);
    }

    printf("\nA bevitt számok abszolútértékei: ");
    for (int i = 0; i < db; i++) {
        printf("%d", masolat[i]);
        if (i < db - 1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("A megadott számok: ");
    for (int i = 0; i < db; i++) {
        printf("%d", eredeti[i]);
        if (i < db - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}