int hw3_islower(int ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int hw3_isupper(int ch)
{
    return (ch >= 'A' && ch <= 'Z');
}
int hw3_isalpha(int ch)
{
    return (hw3_islower(ch) || hw3_isupper(ch));
}
int hw3_isdigit(int ch)
{
    return (ch >= '0' && ch <= '9');
}
int hw3_tolower(int ch)
{
    return (hw3_isupper(ch) ? (ch + 'a'-'A') : ch);
}
int hw3_toupper(int ch)
{
    return (hw3_islower(ch) ? (ch - 'A' - 'a') : ch);
}

#include <stddef.h>
size_t hw3_strlen(const char *str)
{
    size_t m = 0;
    while(str[m] != '\0')
    {
        m += 1;
    }
    return m;
}
char *hw3_strchr(const char *str, int ch)
{
    int s = 0;
    while(str[s] != '\0')
    {
        if (str[s] == ch)
        {
            return ((char *) &str[s]);
        }
        s += 1;
    }
    if (ch == '\0')
    {
        return ((char *) &str[s]);
    }
    return NULL;
}
char *hw3_strcpy(char *dest, const char *src)
{
    int p = 0;
    while(src[p] != '\0')
    {
        dest[p] = src[p];
        p += 1;
    }
    dest[p] = '\0';
    return dest;
}
char *hw3_strcat(char *dest, const char *src)
{
    int q = 0;
    while(dest[q] != '\0')
    {
        q += 1;
    }
    int r = 0;
    while(src[r] != 0)
    {
        dest[q] = src[r];
        q += 1;
        r += 1;
    }
    dest[q] = '\0';
    return dest;
}
int hw3_strcmp(const char *lhs, const char *rhs)
{
    int h = 0;
    while(lhs[h] == rhs[h] && lhs[h] != '\0' && rhs[h] != '\0')
    {
        h += 1;
    }
    return (lhs[h] - rhs[h]);
}
