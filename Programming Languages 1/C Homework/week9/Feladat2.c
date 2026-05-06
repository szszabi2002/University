// 20200416i

#include <stdio.h>
#include <stdlib.h>

int hasonlit(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}

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

    int kapacitas = 1000000;
    int *szamok = (int *)malloc(kapacitas * sizeof(int));
    if (szamok == NULL)
    {
        fprintf(stderr, "Hiba! Nem sikerult memoriat foglalni!\n");
        fclose(fp);
        return 1;
    }

    int db = 0;
    int temp_szam;

    while (fscanf(fp, "%d", &temp_szam) == 1)
    {
        if (db >= kapacitas)
        {
            kapacitas *= 2;
            int *uj_szamok = (int *)realloc(szamok, kapacitas * sizeof(int));
            if (uj_szamok == NULL)
            {
                fprintf(stderr, "Hiba! Memoria ujrafoglalas sikertelen!\n");
                free(szamok);
                fclose(fp);
                return 1;
            }
            szamok = uj_szamok;
        }
        szamok[db] = temp_szam;
        db++;
    }

    fclose(fp);

    qsort(szamok, db, sizeof(int), hasonlit);

    for (int i = 0; i < db; i++)
    {
        printf("%d\n", szamok[i]);
    }

    free(szamok);

    return 0;
}