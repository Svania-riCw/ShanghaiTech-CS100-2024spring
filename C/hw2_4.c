#include <stdio.h>
int cwin(char b[20][20], char m);
int win(char b[20][20], char m);
int cnum(char b[20][20], char m);
int main(void)
{
    int c, d;
    char b[20][20];
    for (int i = 0; i < 15;i++)
    {
        scanf("%s", b[i]);
    }
    c = cnum(b, 'X');
    d = cnum(b, 'O');
    
    if (cwin(b, 'X') != 1 && cwin(b, 'O') != 1)
    {
        if (c>=d)
        {
            if  (win(b, 'X') == 0)
            {
                printf("CannotWin!\n");
            }
        }
        else
        {
            if (win(b, 'O') == 0)
            {
                printf("CannotWin!\n");
            }
        }

    }

}


int cwin(char b[20][20], char m)
{
    for (int i = 0; i < 15;i++)
    {
        for (int j = 0; j < 15;j++)
        {
            if (b[i][j] == m)
            {
                // 横排
                int count1 = 1;
                for (int k = 1; k < 5 && j + k < 15 && j-k>=0;k++)
                {
                    if (b[i][j+k] == m)
                    {
                        count1 += 1;
                    }

                    if (b[i][j-k] == m)
                    {
                        count1 += 1;
                    }

                }
                if (count1 >= 5)
                {
                    printf("AlreadyWin!");
                    return 1;
                }
                


                // 竖排
                int count2 = 1;
                for (int k = 1; k < 5 && i + k < 15 && i-k>=0;k++)
                {
                    if (b[i+k][j] == m)
                    {
                        count2 += 1;
                    }
                    if (b[i-k][j] == m)
                    {
                        count2 += 1;
                    }

                }
                if (count2 >= 5)
                {
                    printf("AlreadyWin!");
                    return 1;
                }
                
                
                // 斜杠1 "\"
                int count3 = 1;
                for (int k = 1; k < 5 && (j + k < 15 && i + k < 15) && (j - k >=0 && i - k >=0) ;k++)
                {
                    if (b[i+k][j+k] == m)
                    {
                        count3 += 1;
                    }
                    if (b[i-k][j-k] == m)
                    {
                        count3 += 1;
                    }

                }
                if (count3 >= 5)
                {
                    printf("AlreadyWin!");
                    return 1;
                }
                

                // 斜杠2 "/"
                int count4 = 1;
                for (int k = 1; k < 5 && (j - k >= 0 && i + k < 15) && (j + k < 15 && i - k >=0);k++)
                {
                    if (b[i+k][j-k] == m)
                    {
                        count4 += 1;
                    }
                    if (b[i-k][j+k] == m)
                    {
                        count4 += 1;
                    }

                }
                if (count4 >= 5)
                {
                    printf("AlreadyWin!");
                    return 1;
                }
                
            }
        }
    }
    return 0;
}

int win(char b[20][20], char m)
{
    for (int i = 0; i < 15;i++)
    {
        for (int j = 0; j < 15;j++)
        {
            if (b[i][j] == m)
            {
                // 横排
                int count1 = 1;
                for (int k = 1; k < 5 && j + k < 15 && j-k >=0;k++)
                {
                    if (b[i][j+k] == m)
                    {
                        count1 += 1;
                    }
                    if (b[i][j-k] == m)
                    {
                        count1 += 1;
                    }

                }
                if (count1 >= 5)
                {
                    return 1;
                }
                else if(count1 == 4)
                {
                    if (j+4<15 && b[i][j+4] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i+1, j + 5);
                        return 2;
                    }
                    else if (j-1>=0 && b[i][j-1] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i+1, j);
                        return 2;
                    }
                }


                // 竖排
                int count2 = 1;
                for (int k = 1; k < 5 && i + k < 15 && i-k>=0;k++)
                {
                    if (b[i+k][j] == m)
                    {
                        count2 += 1;
                    }
                    if (b[i-k][j] == m)
                    {
                        count2 += 1;
                    }

                }
                if (count2 >= 5)
                {
                    return 1;
                }
                else if(count2 == 4)
                {
                    if (i+4<15 && b[i+4][j] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i+5, j+1);
                        return 2;
                    }
                    else if (i-1>=0 && b[i-1][j] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i, j+1);
                        return 2;
                    }
                }
                
                // 斜杠1 "\"
                int count3 = 1;
                for (int k = 1; k < 5 && (j + k < 15 && i + k < 15) && (j - k >= 0 && i - k >=0);k++)
                {
                    if (b[i+k][j+k] == m)
                    {
                        count3 += 1;
                    }
                    if (b[i-k][j-k] == m)
                    {
                        count3 += 1;
                    }

                }
                if (count3 >= 5)
                {
                    return 1;
                }
                else if(count3 == 4)
                {
                    if (j+4<15 && i+4<15 && b[i+4][j+4] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i + 5, j + 5);
                        return 2;
                    }
                    else if (j-1>=0 && i-1>=0 && b[i-1][j-1] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i, j);
                        return 2;
                    }
                }

                // 斜杠2 "/"
                int count4 = 1;
                for (int k = 1; k < 5 && (j - k >= 0 && i + k < 15) && (j + k < 15 && i - k >= 0);k++)
                {
                    if (b[i+k][j-k] == m)
                    {
                        count4 += 1;
                    }
                    if (b[i-k][j+k] == m)
                    {
                        count4 += 1;
                    }

                }
                if (count4 >= 5)
                {
                    return 1;
                }
                else if(count4 == 4)
                {
                    if (j-4>=0 && i+4<15 && b[i+4][j-4] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i + 5, j - 3);
                        return 2;
                    }
                    else if (j+1>=0 && i-1>=0 && b[i-1][j+1] == '.')
                    {
                        printf("Win!\n");
                        printf("%d %d\n", i, j + 2);
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}


int cnum(char b[20][20], char m)
{
    int count = 0;
    for (int i = 0; i < 15;i++)
    {
        for (int j = 0; j < 15;j++)
        {
            if (b[i][j] == m)
            {
                count += 1;
            }
        }
    }
    return count;
}