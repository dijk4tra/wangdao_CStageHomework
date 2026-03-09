#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1(void);

void test1() {
    // 函数指针：就是一个指针，指向函数

    // 声明语法：
    // 函数返回类型 (*函数指针名)(形参列表);

    void (*func_ptr1)(void);

    // func_ptr2 用于指向一个函数，入参是两个int，返回值是int
    int (*func_ptr2)(int, int);

    // func_ptr1、func_ptr2用于指向函数

    // 如果函数指针，出现在形参位置。  * 可以省略
}

void test2(int num1, int num2, int ptr3(int, int)) {
    // 在形参位置，才能省略。 
}

int main(void) {
    
    return 0;
}