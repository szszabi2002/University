// 20200416f

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice(const int n, const int tomb[])
{
    int random_index = rand() % n;
    return tomb[random_index];
}

int main()
{
    srand(time(NULL));
    int szamok[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(szamok) / sizeof(szamok[0]);

    printf("A tomb elemei: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", szamok[i]);
    }
    printf("\n\n");

    printf("Veletlenszeruen kivalasztott elemek:\n");
    for (int i = 0; i < 5; i++)
    {
        int random_elem = choice(n, szamok);
        printf("%d. huzas: %d\n", i + 1, random_elem);
    }

    return 0;
}