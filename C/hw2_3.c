#include <stdio.h>

void exe(int *a, int m)
{
    int b = m >> 13;
    int c = m >> 10 & 0x7;
    int d = m >> 7 & 0x7;
    int e = m & 0x7F;
    if (c!=0)
    {
        switch (b)
        {
        case 0:{
            a[c] += a[d];
            break;}
        case 1:{
            a[c] -= a[d];
            break;}
        case 2:{
            a[c] *= a[d];
            break;}
        case 3:{
            a[c] /= a[d];
            break;}
        case 4:{
            a[c] = e;
            break;}
        case 5:{
            printf("x%d = %d\n", c, a[c]);
            break;}
        }
    }
    else if (c == 0 && b == 5)
        printf("x0 = 0\n");
}

int main(void)
{
    int n;
    unsigned m[100];
    int k[8] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%x", &m[i]);
        exe(k, m[i]);
    }
}