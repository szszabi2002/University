#include <stdio.h>

int valid_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        return 0;
    }
    return 1;

}

int main() {
    double a, b, c;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    printf("\n");
    if (valid_triangle(a, b, c)) {
        printf("A megadott oldalakból egy háromszög megszerkeszthető.\n");
    } else {
        printf("A megadott oldalakbol NEM megszerkeszthető háromszög.\n");
    }
    return 0;
}