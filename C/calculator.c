#include <stdio.h>
int main(void)
{
    double x, y;
    char op;
    char l = 'y';
    while(1)
    {
        scanf("%lf %c %lf", &x, &op, &y);
        if (op == '+')
            printf("%.6lf %c %.6lf == %.6lf\n",x,op,y,x + y);
        else if (op == '-')
            printf("%.6lf %c %.6lf == %.6lf\n",x,op,y,x - y);
        else if (op == '*')
            printf("%.6lf %c %.6lf == %.6lf\n",x,op,y,x * y);
        else if (op == '/') 
            printf("%.6lf %c %.6lf == %.6lf\n",x,op,y,x / y);
        else
            printf("Unknown operator!\n");
        printf("Do you want to continue? (y/n)\n");
        scanf(" %c", &l);
        if (l == 'n')
        {
            break;
        }
        getchar();
    }
    return 0;
}