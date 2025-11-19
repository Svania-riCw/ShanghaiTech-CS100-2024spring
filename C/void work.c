    #include <stdio.h>
int input;
void work(void) {
    printf("%d\n", input);
}

int main(void) {
    scanf("%d", &input);
    work();
}