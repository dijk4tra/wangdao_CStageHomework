#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    int a;
    int b;
    double c;
}

void test2() {
    long l1 = 10;
    int num1 = 666;
}


int main(void) {

    // 局部变量，如果不进行手动初始化，是随机值

    test2();
    test1();
    return 0;
}