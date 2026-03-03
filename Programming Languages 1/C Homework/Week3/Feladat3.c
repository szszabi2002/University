#include <stdio.h>

unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;

    unsigned long long f0 = 0;
    unsigned long long f1 = 1;     
    unsigned long long f2 = 1;

    for (int i = 3; i <= n; i++) {
        f0 = f1 + f2;
        f2 = f1;
        f1 = f0;
    }
    return f0;
}

int main() {
    printf("Az első 100 Fibonacci szám:\n");
    
    for (int i = 1; i <= 100; i++) {
        printf("%d. -> %llu\n", i, fibonacci(i));
    }
    
    return 0;
}