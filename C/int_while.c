#include <stdio.h>

int main(void){
    int x = 1;
    while (x <= 1000) {
        printf("%d\n", x);
        x *= 2;
        getchar();
    }
    return 0;
}