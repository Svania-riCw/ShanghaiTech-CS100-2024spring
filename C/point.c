#include <stdio.h>
int main(void)
{
int num = 5;
int *p = &num;
int **pp = &p;
printf("num = %d, &num = %p\n", num, &num);
printf("p = %p, *p = %d, &p = %p\n", p, *p, &p);
printf("pp = %p, *pp = %p, **pp = %d, &pp = %p\n", pp, *pp, **pp, &p);
}