#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int global_num = 987;

void test1() {
    // 局部变量，是存储在栈帧中的
    // 存储期限：和函数同生共死
    // 函数调用时，活着。函数调用结束，嘎掉
    int num = 10;

    int arr[10];
}

void test2() {
    int len = 80;

    // int arr[80];

    int *arr = malloc(len * sizeof(int));

    if (arr == NULL) {
        printf("malloc failed.\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 80; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);

}

void test3() {
    // 动态内存分配，其实就是使用一系列的函数，来从堆区薅内存

    // 为什么函数是这个形式？
    // malloc(int)
    // 为什么不需要写函数体？
}

int main(void) {
    
    test2();

    return 0;
}