#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    const char *azonosito;
    const char *fajlnev;
    const char *tartalom;
} Sablon;

void kiir_sugo()
{
    printf("Hasznalat: alap <nyelv> [opciok]\n\n");
    printf("Elerheto opciok:\n\n");
    printf("-h, --help        sugo megjelenitese\n");
    printf("-v, --version     verzioinformacio\n");
    printf("--stdout          ne hozzon letre forrasfajlt, a kimenetet irja ki stdout-ra\n\n");
    printf("Tamogatott nyelvek:\n\n");
    printf("* bash       - Bash [script.sh]\n");
    printf("* c          - C [main.c]\n");
    printf("* cs         - C# [Program.cs]\n");
    printf("* java       - Java [Main.java]\n");
    printf("* py         - Python 3 [main.py]\n");
}

void fajl_letrehoz(const char *fajlnev, const char *tartalom)
{
    FILE *fp = fopen(fajlnev, "r");
    if (fp != NULL)
    {
        fclose(fp);
        fprintf(stderr, "Hiba: A(z) %s fajl mar letezik, nem lesz felulirva!\n", fajlnev);
        return;
    }

    fp = fopen(fajlnev, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba: A(z) %s fajl letrehozasakor!\n", fajlnev);
        return;
    }

    fputs(tartalom, fp);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    Sablon sablonok[] = {
        {"bash", "script.sh",
         "#!/usr/bin/env bash\n"
         "\n"
         "echo \"Hello Világ!\"\n"},

        {"c", "main.c",
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n"
         "\n"
         "int main()\n"
         "{\n"
         "    printf(\"Hello Világ!\\n\");\n"
         "    return 0;\n"
         "}\n"},

        {"cs", "Program.cs",
         "using System;\n"
         "\n"
         "namespace HelloVilag\n"
         "{\n"
         "    class Program\n"
         "    {\n"
         "        static void Main(string[] args)\n"
         "        {\n"
         "            Console.WriteLine(\"Hello Világ!\");\n"
         "        }\n"
         "    }\n"
         "}\n"},

        {"java", "Main.java",
         "public class Main {\n"
         "    public static void main(String[] args) {\n"
         "        System.out.println(\"Hello Világ!\");\n"
         "    }\n"
         "}\n"},

        {"py", "main.py",
         "#!/usr/bin/env python3\n"
         "\n"
         "def main():\n"
         "    print(\"Hello Világ!\")\n"
         "\n"
         "if __name__ == '__main__':\n"
         "    main()\n"}};

    int sablonok_szama = sizeof(sablonok) / sizeof(sablonok[0]);
    int kiir_standardra = 0;
    const char *sablon_azonosito = NULL;

    if (argc < 2)
    {
        kiir_sugo();
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            kiir_sugo();
            return 0;
        }
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
        {
            printf("alap v1.2\n");
            return 0;
        }
        else if (strcmp(argv[i], "--stdout") == 0)
        {
            kiir_standardra = 1;
        }
        else
        {
            sablon_azonosito = argv[i];
        }
    }

    if (sablon_azonosito == NULL)
    {
        fprintf(stderr, "Hiba: Nem adtal meg sablon azonositot!\n");
        return 1;
    }

    int talalt = 0;
    for (int i = 0; i < sablonok_szama; i++)
    {
        if (strcmp(sablon_azonosito, sablonok[i].azonosito) == 0)
        {
            talalt = 1;
            if (kiir_standardra)
            {
                printf("%s", sablonok[i].tartalom);
            }
            else
            {
                fajl_letrehoz(sablonok[i].fajlnev, sablonok[i].tartalom);
            }
            break;
        }
    }

    if (!talalt)
    {
        fprintf(stderr, "Hiba: Ismeretlen sablon '%s'.\n", sablon_azonosito);
        return 1;
    }

    return 0;
}