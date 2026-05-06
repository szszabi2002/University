// 20120815k

#include <stdio.h>

int main()
{
    int cellak[601] = {0};

    for (int lepes = 1; lepes <= 600; lepes++)
    {
        for (int i = lepes; i <= 600; i += lepes)
        {
            cellak[i] = !cellak[i];
        }
    }

    printf("A szabadon tavozo eliteltek cellai:\n");
    int elso_kiiratas = 1;

    for (int i = 1; i <= 600; i++)
    {
        if (cellak[i] == 1)
        {
            if (!elso_kiiratas)
            {
                printf(", ");
            }
            printf("%d", i);
            elso_kiiratas = 0;
        }
    }
    printf("\n");

    return 0;
}