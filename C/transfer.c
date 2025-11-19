#include <stdio.h>
char to_uppercase(char x) {
    return x - ('a' - 'A');
}
int main(void){
    char letter;
    printf("Enter a single letter: ");
    scanf("%c", &letter);
    letter = to_uppercase(letter);
    printf("%c\n", letter);
    return 0;
}
