// 20121125b

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strcmpi(const char *s1, const char *s2)
{
    while (*s1 && (tolower((unsigned char)*s1) == tolower((unsigned char)*s2)))
    {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int sztring_hasonlit(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main()
{
    FILE *fp = fopen("nevek.csv", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba a fajl megnyitasakor!\n");
        return 1;
    }

    char pti_hallgatok[100][50];
    int db = 0;
    char sor[100];

    while (fgets(sor, sizeof(sor), fp) != NULL)
    {
        char *nev = strtok(sor, ",");
        strtok(NULL, ",");
        char *szak = strtok(NULL, ",\r\n");

        if (nev != NULL && szak != NULL)
        {
            if (strcmpi(szak, "pti") == 0)
            {
                nev[0] = toupper((unsigned char)nev[0]);
                strcpy(pti_hallgatok[db], nev);
                db++;
            }
        }
    }

    fclose(fp);

    qsort(pti_hallgatok, db, sizeof(pti_hallgatok[0]), sztring_hasonlit);

    for (int i = 0; i < db; i++)
    {
        printf("%s%s", pti_hallgatok[i], (i < db - 1) ? ", " : "\n");
    }

    return 0;
}