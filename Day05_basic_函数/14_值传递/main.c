#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 值传递：指的是函数调用过程中，关于参数的问题
    // 值传递：就是在函数调用过程中，是将参数的值复制了一份，传入函数
    // 在函数内部修改这个变量的值，无法影响外面的变量
}

void change_int(int num) {
    printf("change_int===%d\n", num);
    num = 2345;
    printf("change_int===%d\n", num);
}

//change_int_by_pointer

int main(void) {
    int a = 111;
    change_int(a);

    printf("main===%d\n",a);
    return 0;
}