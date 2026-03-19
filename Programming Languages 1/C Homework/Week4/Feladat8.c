#include <stdio.h>

void print_tomb(int n, int tomb[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", tomb[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    int szamok[] = {4, 7, 34, 23, 67};
    int n = 5;

    print_tomb(n, szamok);

    return 0;
}
