#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char random_char() 
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$^&*()_+-=[]{}|;:,.<>?";
    return charset[rand() % (sizeof(charset) - 1)];
}

void gp(char *s, int len) 
{
    for (int i = 0; i < (len + 1) / 2; i++) 
    {
        s[i] = random_char();
    }

    for (int j = 0; j < len / 2; j++) 
    {
        s[len - j - 1] = s[j];
    }

    s[len] = '\0';
}

void gen(char *s, int len) {
    for (int i = 0; i < len; i++) 
    {
        s[i] = 'a' + rand() % 26; 
    }
    s[len] = '\0'; 
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int max = atoi(argv[2]);

    printf("%d\n", n);

    char **test = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        test[i] = malloc((max + 1) * sizeof(char)); 
    }
    
    srand(time(NULL));  
    
    for (int i = 0; i < n; i++) 
    {
        int len = rand() % max + 1;  
        if (i % 2 == 1) {
            gp(test[i], len); 
        } else {
            gen(test[i], len); 
        }
        printf("%d\n", len);
        printf("%s\n", test[i]);  
    }
    
    for (int i = 0; i < n; i++) {
        free(test[i]);  
    }
    free(test);  
    
    return 0;
}