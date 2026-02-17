#include <stdio.h>

int main()
{
    int a, b;
    printf("Kérem a téglalap A és B oldalát (cm): ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("A téglalap terület: %d\n", a * b);
    printf("A téglalap kerület: %d\n", 2 * (a + b));
    return 0;
}