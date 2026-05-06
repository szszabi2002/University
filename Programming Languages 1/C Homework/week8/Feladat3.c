// 20200326d B+C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int db, also, felso;

    printf("Hány db random számot kérsz?\n");
    scanf("%d", &db);

    printf("Alsó határ: ");
    scanf("%d", &also);

    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &felso);

    if (felso - also + 1 < db)
    {
        printf("Hiba: Nincs elegendő különböző szám ebben az intervallumban!\n");
        return 1;
    }

    int szamok[db];
    srand(time(NULL));

    for (int i = 0; i < db; i++)
    {
        int uj_szam;
        int ismetlodes;

        do
        {
            ismetlodes = 0;
            uj_szam = rand() % (felso - also + 1) + also;

            for (int j = 0; j < i; j++)
            {
                if (szamok[j] == uj_szam)
                {
                    ismetlodes = 1;
                    break;
                }
            }
        } while (ismetlodes == 1);

        szamok[i] = uj_szam;
    }

    for (int i = 0; i < db - 1; i++)
    {
        for (int j = 0; j < db - i - 1; j++)
        {
            if (szamok[j] > szamok[j + 1])
            {
                int temp = szamok[j];
                szamok[j] = szamok[j + 1];
                szamok[j + 1] = temp;
            }
        }
    }

    printf("\nA generált számok: ");
    for (int i = 0; i < db; i++)
    {
        printf("%d ", szamok[i]);
    }
    printf("\n");

    return 0;
}