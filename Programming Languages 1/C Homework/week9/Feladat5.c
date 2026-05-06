// 20200411a

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int n, char tomb[])
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = temp;
    }
}

int main()
{
    srand(time(NULL));

    char kisbetuk[] = "abcdefghijklmnopqrstuvwxyz";
    char nagybetuk[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char szamok[] = "0123456789";
    char specialis[] = ".,;'";
    char osszes[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,;'";

    int hossz = rand() % 5 + 8;
    char jelszo[13];

    jelszo[0] = kisbetuk[rand() % 26];
    jelszo[1] = nagybetuk[rand() % 26];
    jelszo[2] = szamok[rand() % 10];
    jelszo[3] = specialis[rand() % 4];

    for (int i = 4; i < hossz; i++)
    {
        jelszo[i] = osszes[rand() % 66];
    }

    jelszo[hossz] = '\0';
    shuffle(hossz, jelszo);
    printf("%s\n", jelszo);

    return 0;
}