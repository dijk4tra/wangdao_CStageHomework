#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
编写程序，从键盘输入输入中读取一个整数n，动态分配一个长度为n的整型数组。
将数组元素初始化为1, 2, 3, ..., n，并输出打印数组内容，最后释放内存。
注意:
    1.初始化内存块时可以直接使用下标来操作内存块。
    2.遍历打印数组元素取值时，请使用指针来实现操作。
*/

int main(void) {
    int n = 0;
    printf("请输入一个正整数n，用于动态分配一个长度为n的整型数组：");
    scanf("%d", &n);

    // C语言允许隐式类型转换，(int *)显式强制类型转换可加可不加
    int *arr_p = (int *)malloc(n * sizeof(int));

    if (arr_p == NULL) {
        printf("malloc failed !");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        arr_p[i] = i + 1;
    }

    printf("已创建并初始化该数组，该数组的内容为：");
    for (int i = 0; i < n; i++) {
        printf("%d ",*(arr_p + i));
    }
    printf("\n");

    free(arr_p);    // 释放内存
    arr_p = NULL;   // 将指针置为空指针

    return 0;
}