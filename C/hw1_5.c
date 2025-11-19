#include <stdio.h>
#include <math.h>
int main(void)
{
    int a,b,c,m;
    double x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    m = b * b - 4 * a * c;
    x1 = (-b - sqrt(m)) / (2 * a);
    x2 = (-b + sqrt(m)) / (2 * a);
    if (a == 0)
    {
        if (b==0 && c==0)
        {
            printf("x\\in\\mathbb{R}\n");
        }
        else if(b==0 && c!=0)
        {
            printf("No solution.\n");
        }
        else if(b!=0)
        {
            printf("x = %.3f", (float) -c / b);
        }
    }
    else
    {
        if (m < 0)
        {
            printf("No solution.\n");
        }
        else if (m == 0)
        {
            printf("x1 = x2 = %.3f\n", (float) -b / (2*a));
        }
        else
        {
            if (a < 0)
            {
                printf("x1 = %.3f, x2 = %.3f\n", x2, x1);
            }
            else if(a > 0)
            {
                printf("x1 = %.3f, x2 = %.3f\n", x1, x2);
            }
        }
    }
}