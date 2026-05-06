// Implementálja az int strcmpi(const char* s1, const char* s2); szignatúrával rendelkező függvényt. A fv. hasonlóan működjön az strcmp() fv.-hez, de a kis- és nagybetűket NE különböztesse meg. Vagyis pl. az "ez" és az "EZ" szavakat tekintse egyformának.

#include <stdio.h>
#include <ctype.h>

int strcmpi(const char *s1, const char *s2)
{
    while (*s1 != '\0' && (tolower((unsigned char)*s1) == tolower((unsigned char)*s2)))
    {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int main()
{
    printf("Eredmeny (ez vs EZ): %d\n", strcmpi("ez", "EZ"));
    printf("Eredmeny (Alma vs also): %d\n", strcmpi("Alma", "also"));
    printf("Eredmeny (Zebra vs zege): %d\n", strcmpi("Zebra", "zege"));
    return 0;
}