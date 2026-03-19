#include <stdio.h>

int main()
{
    int ketto = sizeof("x");
    int nulla = ketto - ketto;
    int hat = sizeof("xxxxx");
    printf("%d%d%d%d\n", ketto, nulla, ketto, hat);
    return nulla;
}