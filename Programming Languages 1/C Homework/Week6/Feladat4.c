#include <stdio.h>

int main() {
    int megadott_szamok[100] = {0};
    int szam;
    int kulonbozo_db = 0;

    printf("Adj meg 0 végjelig egész számokat az [1, 99] intervallumból!\n");

    while (1) {
        printf("Szám: ");
        scanf("%d", &szam);

        if (szam == 0) {
            break;
        }

        if (szam >= 1 && szam <= 99) {
            megadott_szamok[szam] = 1;
        } else {
            printf("Ez a szám kívül esik az elfogadható intervallumon!\n");
        }
    }

    for (int i = 1; i <= 99; i++) {
        if (megadott_szamok[i] == 1) {
            kulonbozo_db++;
        }
    }

    printf("\n%d db különböző szám lett megadva.\n", kulonbozo_db);

    if (kulonbozo_db > 0) {
        printf("Ezek (növekvő sorrendben): ");
        int kiirva = 0;
        for (int i = 1; i <= 99; i++) {
            if (megadott_szamok[i] == 1) {
                printf("%d", i);
                kiirva++;
                if (kiirva < kulonbozo_db) {
                    printf(", ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}