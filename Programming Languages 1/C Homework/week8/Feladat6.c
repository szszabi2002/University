// 20200409c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", argv[1]);
        return 1;
    }

    int count = 0;
    int ch;
    int utolso_karakter = '\n';

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
        utolso_karakter = ch;
    }

    if (utolso_karakter != '\n' && utolso_karakter != EOF)
    {
        count++;
    }

    fclose(fp);

    printf("%d\n", count);

    return 0;
}