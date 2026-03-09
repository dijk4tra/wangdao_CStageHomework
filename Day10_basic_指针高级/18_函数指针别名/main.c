#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int DataType;

//typedef int (*ptr1)(int, int) FuncPtr;

// 这个就变成了函数指针的别名
typedef int (*FuncPtr)(int, int);

void test1() {
    // 由于函数指针的语法过于奇葩，所以建议给函数指针起个别名

    // ptr1 就是一个函数指针
    FuncPtr ptr1;
    // int (*ptr2)(int, int);

    // int num;
    // FuncPtr： 别名。相当于是int，是类型
    // ptr2: 是一个变量。相当于是num
}

int main(void) {
    
    return 0;
}