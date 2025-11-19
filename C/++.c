#include <stdio.h>
int main(void) {
// int x = 42;
// printf("%d\n", ++x);
// int y = x++;
// printf("%d\n", y);


int x = 10;
int y = 10;
int result1 = x++ + ++x;
int result2 = ++y + y++;
printf("x = %d, result1 = %d\n", x, result1);
printf("y = %d, result2 = %d\n", y, result2);
return 0;
}

