#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // C中的整形
    // short   int   long   long long
    // 又可以整体分为两类：有符号数、无符号数
    // int：占4个字节
    // 10000000000000000000000000000001
    // 如果最高位，都用来表示数据，就是无符号数
    // 如果最高位，都用来表示正负，就是有符号数
}

void test2(){
    // 有符号数
    // 100000000000000000000000000000000001
    // 原码、反码、补码知识点复习
}

void test3() {
    // 无符号数，使用时需要注意
    int num = -50;
    unsigned int num2 = 100;
    if (num > num2) {
        // 有符号数和无符号数进行计算，会将有符号数视为无符号数
        printf("num > num2\n");
    }
    else {
        printf("num < num2\n");
    }
}

int main(void) {
    test3();
    return 0;
}