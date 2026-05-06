// 20240424a

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Hasznalat: %s <sorok_szama> <min_hossz> <max_hossz>\n", argv[0]);
        return 1;
    }

    int db = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    srand(time(NULL));

    for (int i = 0; i < db; i++)
    {
        int hossz = rand() % (max - min + 1) + min;
        for (int j = 0; j < hossz; j++)
        {
            char c = (rand() % (126 - 33 + 1)) + 33;
            putchar(c);
        }
        putchar('\n');
    }

    return 0;
}