#include <stdio.h>

typedef char* string;

int rfind_char(string s, char c) {
    int utolso_index = -1; 
    int i = 0;
    
    while (s[i] != '\0') {
        if (s[i] == c) {
            utolso_index = i;
        }
        i++;
    }
    
    return utolso_index;
}

int main() {
    printf("rfind_char(\"Abba\", 'b') -> %d\n", rfind_char("Abba", 'b'));
    printf("rfind_char(\"Abba\", 'a') -> %d\n", rfind_char("Abba", 'a'));
    printf("rfind_char(\"Abba\", 'x') -> %d\n", rfind_char("Abba", 'x'));
    printf("rfind_char(\"Aladar\", 'a') -> %d\n", rfind_char("Aladar", 'a'));

    return 0;
}