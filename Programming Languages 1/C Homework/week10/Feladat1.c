// 20200416i dinamikus tömb adatszerkezet használatával

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} DynArray;

void da_init(DynArray *self)
{
    self->capacity = 10;
    self->size = 0;
    self->data = (int *)malloc(self->capacity * sizeof(int));
    if (self->data == NULL)
    {
        fprintf(stderr, "Hiba a memoriafoglalasnal!\n");
        exit(1);
    }
}

void da_append(DynArray *self, int value)
{
    if (self->size >= self->capacity)
    {
        self->capacity *= 2;
        self->data = (int *)realloc(self->data, self->capacity * sizeof(int));
        if (self->data == NULL)
        {
            fprintf(stderr, "Hiba a memoria ujrafoglalasanal!\n");
            exit(1);
        }
    }
    self->data[self->size] = value;
    self->size++;
}

void da_clear(DynArray *self)
{
    free(self->data);
    self->capacity = 10;
    self->size = 0;
    self->data = (int *)malloc(self->capacity * sizeof(int));
}

void da_destroy(DynArray *self)
{
    free(self->data);
    self->data = NULL;
    self->size = 0;
    self->capacity = 0;
}

int hasonlit(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Hiba! Adja meg a fajl nevet parancssori argumentumkent!\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s fajlt nem sikerult megnyitni!\n", argv[1]);
        return 1;
    }

    DynArray szamok;
    da_init(&szamok);

    int temp_szam;
    while (fscanf(fp, "%d", &temp_szam) == 1)
    {
        da_append(&szamok, temp_szam);
    }
    fclose(fp);

    qsort(szamok.data, szamok.size, sizeof(int), hasonlit);

    printf("Rendezett:\n");
    for (int i = 0; i < szamok.size; i++)
    {
        printf("%d\n", szamok.data[i]);
    }

    printf("\nda_clear teszteles\n");
    da_clear(&szamok);
    printf("Tomb merete a torles utan: %d\n", szamok.size);

    da_append(&szamok, 42);
    da_append(&szamok, 84);
    printf("Ujra hozzaadott elemek: %d, %d\n", szamok.data[0], szamok.data[1]);

    da_destroy(&szamok);

    return 0;
}