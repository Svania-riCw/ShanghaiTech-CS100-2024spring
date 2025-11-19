#include <stdio.h>
int main(void)
{
    char op;
    int a, b;
    printf("Input:");
    scanf("%d%d", &a, &b);
    switch (op)
    {
        case '+':
            printf("%lf\n", a + b);
            break;
        case '-':
            printf("%lf\n", a + b);
            break;
        case '*':
            printf("%lf\n", a + b);
            break; 
        case '/':
            printf("%lf\n", a + b);
            break;   
        default:
            printf("Invalid operator!\n");
            break;
    }
}