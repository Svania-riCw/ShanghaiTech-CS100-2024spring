#include<stdio.h>
// void swap(int *pa, int *pb) {
//     int tmp = *pa;
//     *pa = *pb;
//     *pb = tmp;
//   }
//   int main(void) {
//     int x = 10, y = 15;
//     int *px = &x;
//     int *py = &y;
//     swap(px, py);
//     printf("%d %d\n", x, y);
//   }
// void fun(int x) {
//     x = 42;
//     }
// int main(void) {
// int i = 30;
// fun(i);
// printf("%d\n", i);
// }


//        if( k[k[m]] != 0 && k[k[m]] != k[m])
// {
//     s[k[k[m]]] = s[k[k[m]]] ^ (s[k[k[m]]] << 3 | s[n] >> 29);
//     if (k[k[k[m]]] != 0 && k[k[k[m]]] != k[k[m]] && k[k[k[m]]] != k[m])
//     {
//         s[k[k[k[m]]]] = s[k[k[k[m]]]] ^ (s[k[k[k[m]]]] << 4 | s[n] >> 28);
//         if (k[k[k[k[m]]]] != 0 && k[k[k[k[m]]]]!= k[k[k[m]]] &&  k[k[k[k[m]]]] != k[k[m]] && k[k[k[k[m]]]] != k[m])
//         {
//             s[k[k[k[k[m]]]]] = s[k[k[k[k[m]]]]] ^ (s[k[k[k[k[m]]]]] << 5 | s[n] >> 27);
//         }
//     }
#include <stdio.h>

int cyclic_left_shift(int value, int shift) {
    return (value << shift) | (value >> (32 - shift));
}

void update(int s[], int p[], int x, int y) {
    int current = x;
    int shift = 1;
    while (1) {
        int next = p[current];
        if (next == current) break; // 如果回到自身，停止
        s[next] ^= cyclic_left_shift(s[x], shift);
        shift++;
        current = next;
    }
    p[x] = y;
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);

    int s[1000];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    int p[1001]; // p[0] unused
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int j = 0; j < q; j++) {
        int x, y;
        scanf("%d %d", &x, &y);
        update(s, p, x, y);
    }

    int min_index = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] < s[min_index]) {
            min_index = i;
        }
    }

    printf("%d\n", min_index);
    printf("%d\n", s[min_index]);

    return 0;
}

  