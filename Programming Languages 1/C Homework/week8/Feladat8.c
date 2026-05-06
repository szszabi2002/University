// 20200409e

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp_in = fopen("in.txt", "r");
    if (fp_in == NULL)
    {
        fprintf(stderr, "Hiba! Az in.txt fajlt nem sikerult megnyitni!\n");
        return 1;
    }

    printf("# in.txt sikeresen megnyitva\n");

    FILE *fp_out = fopen("out.txt", "w");
    if (fp_out == NULL)
    {
        fprintf(stderr, "Hiba! Az out.txt fajlt nem sikerult megnyitni!\n");
        fclose(fp_in);
        return 1;
    }

    printf("# 0,5-nél nagyobb számok szűrése...\n");

    char buffer[256];
    int count = 0;

    while (fscanf(fp_in, "%s", buffer) == 1)
    {
        if (atof(buffer) > 0.5)
        {
            fprintf(fp_out, "%s\n", buffer);
            count++;
        }
    }

    printf("# szűrés vége\n");

    fclose(fp_in);
    fclose(fp_out);

    printf("# out.txt bezárva\n");
    printf("# out.txt-be kiírt számok mennyisége: %d db\n", count);

    return 0;
}