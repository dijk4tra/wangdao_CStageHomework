#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 函数指针：就是一个指针，指向函数，指向代码段
    // 代码段中存放的是机器指令

    // 定义语法比较怪
    // void (*func_ptr1)(void); //这个指针，专门指向无入参，无返回值的函数

    void (*func_ptr1)(void) = test1;
    // func_ptr1();
}

void test2(int num ,float f1, int func_ptr2(int num1, int num2)) {
    
}

int main(void) {
    
    return 0;
}