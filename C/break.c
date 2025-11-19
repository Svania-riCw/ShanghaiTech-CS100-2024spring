#include <stdio.h>

int main(void)
{
    // int n = 10;
    // double x, y;
    // if (scanf("%lf%lf", &x, &y) == 2)
    // {
    //     while(n>0)
    //     {
    //         if (n == 6)
    //         {
    //             n--;
    //             continue;
    //         }
    //         // if (n == 4)
    //         // {
    //         //     break;
    //         // }
    //         printf("(%lf,%lf)\n", x, y);
    //         n--;
    //     }
    // }
    // else
    // {
    //     printf("Invalid Input.\n");
    // }
    int n = 5;
    int sum;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        if (x == 42)
        {
            continue;
        }
        sum += x;
    }
    printf("%d\n", sum);
}

