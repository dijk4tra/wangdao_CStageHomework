#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INIT_LEN 10

void test1() {
    int arr[5];
    char arr2[8];
}

void test2() {
    //数组声明的时候，中括号中，只能写常量
    int arr1[8];

    const int len = 10;
    //int arr2[len]; //const修饰的只读变量不能作为数组长度

    int arr3[INIT_LEN]; //可以使用宏常量作为数组长度的表示
}

void test3() {
    // 从C99开始，变长数组是允许的。但是不建议使用。
    int len = 10;
    //int arr2[len];
}

void test4() {
    int arr1[8];
}

int main(void) {
    test4();
    return 0;
}