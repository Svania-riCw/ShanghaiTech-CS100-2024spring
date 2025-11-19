#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void des(char *a, char *next_a);
char *stand(char *v);
char *type(char *name);


int main(int a, char *b[]) {
    for (int i = 1; i < a; i++) {
        if (strcmp(b[i], "-o") == 0)
        {
            des(b[i], b[i + 1]);
            i++;
        } 
        else if (strcmp(b[i], "-I") == 0) 
        {
            des(b[i], b[i + 1]);
            i++;
        } 
        else if (strncmp(b[i], "-std=", 5) == 0) 
        {
            des(b[i], NULL);
        } 
        else 
        {
            des(b[i], NULL);
        }
    }
    return 0;
}


void des(char *a, char *next_a) 
{
    if (strcmp(a, "-Wall") == 0) 
    {
        printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
    } 
    else if (strcmp(a, "-Wpedantic") == 0) 
    {
        printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
    } 
    else if (strcmp(a, "-Wextra") == 0) 
    {
        printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
    } 
    else if (strcmp(a, "-Werror") == 0) 
    {
        printf("-Werror: Make all warnings into errors.\n");
    } 
    else if (strcmp(a, "-o") == 0) 
    {
        printf("-o %s: Place the primary output in file %s.\n", next_a, next_a);
    } 
    else if (strcmp(a, "-I") == 0) 
    {
        printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", next_a, next_a);
    } 
    else if (strncmp(a, "-std=", 5) == 0) 
    {
        char *l = a + 5;
        char *m1 = stand(l);
        printf("-std=%s: Set the language standard to %s.\n", l, m1);
        free(m1);
    } 
    else 
    {
        printf("%s: %s as input file.\n", a, type(a));
    }
}


char *stand(char *v) {
    char *re = NULL;
    if (strncmp(v, "c", 1) == 0) 
    {
        re = malloc(20);
        if (re) 
        {
            snprintf(re, 20, "ISO C%s", v + 1);
        }
    } 
    else if (strncmp(v, "c++", 3) == 0) 
    {
        re = malloc(20);
        if (re) 
        {
            snprintf(re, 20, "ISO C%s", v + 1);
        }
    } 
    else if (strncmp(v, "gnu", 3) == 0) 
    {
        re = malloc(30);
        if (re) 
        {
            snprintf(re, 30, "GNU dialect of C%s", v + 3);
        }
    } 
    else if (strncmp(v, "gnu++", 5) == 0) 
    {
        re = malloc(30);
        if (re) {
            snprintf(re, 30, "GNU dialect of C%s", v + 5);
        }
    }
    
    return re;
}


char *type(char *name) 
{
    char *e = strrchr(name, '.');
    if (e != NULL) {
        if (strcmp(e, ".c") == 0) 
        {
            return "C source code";
        } 
        else if (strcmp(e, ".h") == 0) 
        {
            return "C/C++ header file";
        } 
        else if (strcmp(e, ".cpp") == 0 || strcmp(e, ".C") == 0 || strcmp(e, ".cc") == 0 || strcmp(e, ".cxx") == 0) 
        {
            return "C++ source code";
        } 
        else if (strcmp(e, ".hpp") == 0 || strcmp(e, ".hxx") == 0) 
        {
            return "C++ header file";
        }
    }
    return NULL;
}