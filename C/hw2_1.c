#include <stdio.h>

int b, c, d, e;
int reverse(int a)
{
    int result = 0;
    while(a != 0)
    {
        b = a % 10;
        result = result * 10 + b;
        a /= 10;
    }
    return result;
}
int find_max(int a)
{
    int m[4];
    m[0] = a % 10;
    a /= 10;
    m[1] = a % 10;
    a /= 10;
    m[2] = a % 10;
    a /= 10;
    m[3] = a % 10;
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3-i;j++)
        {
            if (m[j] > m[j+1])
            {
                int m1 = m[j];
                m[j] = m[j + 1];
                m[j + 1] = m1;
            }
        }
    }
    return m[3] * 1000 + m[2] * 100 + m[1] * 10 + m[0];
}

int main(void)
{
    int n;
    int a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        c = reverse(a[i]);
        if (a[i] > 9999)
        {
            printf("%d contains more than 4 digits.\n", a[i]);
        }
        else if (find_max(a[i]) == reverse(find_max(a[i])))
        {
            printf("%d is a repdigit.\n", a[i]);
        }
        else
        {
            while(a[i] != 6174 && a[i] != 0)
            {
                a[i] = find_max(a[i]);
                c = reverse(a[i]);
                d = a[i] - c;
                printf("%d - %d = %d\n", a[i], c, d);
                a[i] = d;
            }
        }
    }
}