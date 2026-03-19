#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1(){
    // const 是一个关键字
    // 加了const，就可以让一个变量，“看起来”变成了常量

    const int num = 999;
    // num = 987654;

    // 到底能否修改呢？可以被修改！
}

void test2() {
    const int num = 9876;
    // num = 987654;
    printf("num = %d\n", num);

    scanf("%d", &num);
    printf("num = %d\n", num);

    // 加了const的变量也可以用scanf修改！
}

void test3() {
    // const有什么用？
    // 可以帮助我们避免一些写错了的情况

    const int num1;
    int num2;
    int num3;
    int num4;
    int num5;

    //num1 = 987; // 这样就会出现报错，可以避免此类意外修改num1的值的情况
    // 但还是可以通过scanf或指针来修改num1的值
    // const 只能防君子不能防小人！
}

int main(void) {
    test2();
    return 0;
}