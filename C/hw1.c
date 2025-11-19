#include <stdio.h>

double pow1(double d, int e)
{
    double re = 1.0;
    for (int i = 0; i < e; i++) {
        re *= d;
    }
    return re;
}

int main(void) 
{
    int deg;
    scanf("%d", &deg);
    double a[1000];

    for (int i = 0; i < deg + 1; i++) 
    {
        scanf("%lf", &a[i]);
    }

    int num;
    scanf("%d", &num);
    double b;

    for (int j = 0; j < num; j++) 
    {
        double input;
        scanf("%lf", &input);
        b = input;
        double sum = a[0];
        for (int k = 1; k < deg + 1; k++)
        {
            sum += pow1(b, k) * a[k];
        }
        printf("%.3f\n", sum);
    }

    return 0;
}

