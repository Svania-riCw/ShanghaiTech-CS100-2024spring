#include <stdio.h>
void update(unsigned s[10000], int k[10000], int m);
// m << n | m >> 32-n  // 循环左移


int main(void)
{
    int n, q;
    scanf("%d %d", &n, &q);

    unsigned s[10000] = {0};
    for (int i = 0; i < n;i++)
    {
        scanf("%u", &s[i+1]);
    }

    int x[10000] = {0};
    int y[10000] = {0};
    int k[10000] = {0};
    for (int j = 0; j < q;j++)
    {
        scanf("%d %d", &x[j], &y[j]);
        k[x[j]] = y[j];
        update(s, k, x[j]);
    }
    int num = 1;
    unsigned min = s[1];
    for (int i = 0; i < n;i++)
    {
        if(s[i+1] < min)
        {
            min = s[i+1];
            num = i+1;
        }
    }
    printf("%d\n", num);
    printf("%u\n", s[num]);
    for (int i = 1; i < 4;i++)
    {
        printf("%u\n", s[i]);
    }
}

void update(unsigned s[10000], int k[10000], int m)
{
    
    int g[10000] = {0};
    int count = 0;
    int e = m;
    while (k[m]!=0 && g[k[m]]!=1 && k[m] != m && k[m] != e)
    {
        int l = m;
        int f;
        if (count %32 == 31)
        {
            s[k[l]] = s[k[l]] ^ s[e];
            printf("%u\n", s[k[l]]);
        }
        else
        {
            f = (1 + count) % 32;
            s[k[l]] = s[k[l]] ^ ((s[e] << f | (s[e] >> (32 - f))));
            printf("%u\n", s[k[l]]);
        }

        count += 1;
        g[k[l]] += 1;
        m = k[m];
        // printf("%d\n", s[k[l]]);
    }

}







