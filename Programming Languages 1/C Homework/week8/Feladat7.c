// 20200409d

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    double osszeg = 0.0;
    char buffer[256];

    while (fscanf(fp, "%s", buffer) == 1)
    {
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (buffer[i] == ',')
            {
                buffer[i] = '.';
                break;
            }
        }
        osszeg += atof(buffer);
    }

    fclose(fp);

    printf("%.20f\n", osszeg);

    return 0;
}