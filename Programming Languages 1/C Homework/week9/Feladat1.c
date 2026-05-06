// 20200416h

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Hiba! Adja meg a fajl nevet parancssori argumentumkent!\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s fajlt nem sikerult megnyitni!\n", argv[1]);
        return 1;
    }

    int szamok[10000];
    int db = 0;
    int temp_szam;

    while (fscanf(fp, "%d", &temp_szam) == 1)
    {
        if (db < 10000)
        {
            szamok[db] = temp_szam;
            db++;
        }
    }

    fclose(fp);

    for (int i = 0; i < db - 1; i++)
    {
        for (int j = 0; j < db - i - 1; j++)
        {
            if (szamok[j] > szamok[j + 1])
            {
                int csere = szamok[j];
                szamok[j] = szamok[j + 1];
                szamok[j + 1] = csere;
            }
        }
    }

    for (int i = 0; i < db; i++)
    {
        printf("%d\n", szamok[i]);
    }

    return 0;
}