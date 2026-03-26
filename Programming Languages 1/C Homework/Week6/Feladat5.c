#include <stdio.h>
#include <stdlib.h>

int main() {
    int db, also, felso;

    printf("Hány db random számot kérsz?\n");
    scanf("%d", &db);

    printf("Alsó határ: ");
    scanf("%d", &also);

    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &felso);

    int szamok[db];

    for (int i = 0; i < db; i++) {
        szamok[i] = rand() % (felso - also + 1) + also;
    }

    printf("\nA generált számok: ");
    for (int i = 0; i < db; i++) {
        printf("%d ", szamok[i]);
    }
    printf("\n");

    return 0;
}