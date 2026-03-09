#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* test1() {
    int a = 10086;
    return &a;
}

int main(void) {
    // 局部变量，是和栈帧同生共死的
    
    int* p = test1();

    // 走到这一行，test1的函数栈帧是否还活着？

    printf("%d\n", *p);

    return 0;
}