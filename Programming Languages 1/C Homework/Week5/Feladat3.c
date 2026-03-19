#include <stdio.h>

typedef char* string;

int char_count(string s, char c) {
    int count = 0;
    int i = 0;
    
    while (s[i] != '\0') {
        if (s[i] == c) {
            count++;
        }
        i++;
    }
    
    return count;
}

int main() {
    printf("char_count(\"Abba\", 'b') -> %d\n", char_count("Abba", 'b'));
    printf("char_count(\"Abba\", 'a') -> %d\n", char_count("Abba", 'a'));
    printf("char_count(\"Abba\", 'x') -> %d\n", char_count("Abba", 'x'));

    return 0;
}