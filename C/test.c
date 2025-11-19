#include<stdio.h>
int main(void)
{
    int a = 1;
    int b = (a++, a + 100, a - 10);
    printf("%d\n", b);
}