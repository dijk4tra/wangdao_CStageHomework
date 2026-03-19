#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    const int arr[5] = { 10,20,30,40,50 };

    //arr[0] = 8;

    // const 也可用于修饰数组，让数组里面的内容不被轻易改掉。
}

int main(void) {
    printf("hello world!\n");
    return 0;
}