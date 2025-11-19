#include <stdio.h>
#include <stdlib.h>

int main() {
    // 请求分配 10 个整数的内存空间
    int *arr = (int *)malloc(10 * sizeof(int));

    // 检查内存是否成功分配
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    // 使用分配的内存
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;  // 初始化数组
    }

    // 打印数组内容
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 释放分配的内存
    free(arr);

    return 0;
}