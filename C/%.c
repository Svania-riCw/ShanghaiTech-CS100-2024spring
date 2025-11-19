#include <stdio.h>

long double m;
const long double m1 = 9007199254740993;
long double m2 = 9007199254740993;

long double midpoint(long double a, long double b)
{
    m = (a + b) / 2.0;
    return m;
}

int main(void) 
{
    printf("%Lf\n", midpoint(m1, m2));
    // if (a == b)
    // {
    //     printf("equal.\n");
    // }
    // else{
    //     printf("%d\n", a);
    //     printf("%d\n", b);
    //     printf("not");
    // unsigned uval = -5;
    // int ival = 45;
    // // int x, y;
    // // scanf("%d %d", &x, &y);
    // printf("%d\n", uval);
    // printf("%d\n", -100 / ival);
    return 0;
}

