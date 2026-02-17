#include <stdio.h>
#include <math.h>

int main()
{
    int r;
    printf("Kérem a kör sugarát (cm): ");
    scanf("%d", &r);
    printf("A kör kerület: %.2f cm\n", 2 * r * M_PI);
    printf("A kör terület: %.2f cm²\n", r * r * M_PI);
    return 0;
}