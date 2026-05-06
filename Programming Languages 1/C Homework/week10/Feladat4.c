// Írja meg a my_strfry() eljárást. Ez kap egy sztringet, amiben a karaktereket összekeveri. Ez az eljárás helyben módosítsa a sztringet! A programot lehessen Windows alatt is futtatni. Korábban már volt egy házi feladat, amiben egy tömb elemeit kellett összekeverni; annak a kódját újra lehet hasznosítani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void my_strfry(char *s)
{
    int n = strlen(s);
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main()
{
    srand(time(NULL));
    char szoveg[] = "Programozas";
    printf("Eredeti: %s\n", szoveg);
    my_strfry(szoveg);
    printf("Keverve (1): %s\n", szoveg);
    my_strfry(szoveg);
    printf("Keverve (2): %s\n", szoveg);

    return 0;
}