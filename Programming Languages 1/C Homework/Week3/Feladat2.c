#include <stdio.h>

int main() {
    int m;
    
    printf("Magasság: ");
    scanf("%d", &m);
    printf("\n");
    while (m <= 0 || m % 2 == 0) {
        printf("A magasságnak pozitiv páratlan számnak kell lennie!\n");
        return 1;
    }

    int felso_resz = m / 2 + 1;
    for (int i = 1; i <= felso_resz; i++) {
        for (int j = 1; j <= felso_resz - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    for (int i = felso_resz - 1; i >= 1; i--) {
        for (int j = 1; j <= felso_resz - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}