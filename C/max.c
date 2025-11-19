#include <stdio.h>

int max(int a, int b) {
    if (a<b)
        return b;
    else
        return a;
}

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", max(a,b));
    return 0;
}