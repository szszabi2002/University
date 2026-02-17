#include <stdio.h>

int main()
{
    int a, b;
    printf("Kérem a téglalap A oldalát (cm): ");
    scanf("%d", &a);
    printf("Kérem a téglalap B oldalát (cm): ");
    scanf("%d", &b);
    printf("A téglalap kerület: %d cm\n", 2 * (a + b));
    printf("A téglalap terület: %d cm²\n", a * b);
    return 0;
}