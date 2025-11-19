#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int m;
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &m);
        char *s = malloc((m+1) * sizeof(char));
        scanf("%s", s);
        int k = 0;
        for (int j = 0; j < m/2;j++)
        {    
            if (s[j] != s[m - j-1])
            {
                printf("No\n");
                k += 1;
                break;
            }
        }
        if (k == 0)
        {
            printf("Yes\n");
        }
        free(s);
    }
}