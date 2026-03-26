#include <stdio.h>

void fill_char_array(char c[]) {
    int j = 0;
    for(int i = (int)'a'; i <= (int)'z'; i++) {
        c[j] = (char)i;
        j = j + 1;
    }
}

void fill_string_array(char c[]) {
    int j = 0;
    for(int i = (int)'a'; i <= (int)'z'; i++) {
        c[j] = (char)i;
        j = j + 1;
    }
    c[j] = '\0';
}

int main() {
    char abece_tomb[26];
    
    fill_char_array(abece_tomb);
    
    printf("A) verzió: ");
    for(int i = 0; i < 26; i++) {
        printf("%c", abece_tomb[i]);
    }
    printf("\n");

    char abece_sztring[27];
    
    fill_string_array(abece_sztring);
    
    printf("B) verzió: %s\n", abece_sztring);

    return 0;
}