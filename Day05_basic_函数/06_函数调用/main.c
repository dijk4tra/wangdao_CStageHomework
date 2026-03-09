#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
函数的调用过程，是使用栈来存储的
main函数调用过程中，会创建一个结构（栈帧），用于存储函数的一些信息
1.凡是要调用一个函数，就会创建一个栈帧，并将栈帧压栈
2.局部变量，永远是栈顶栈帧有效
3.函数调用结束，栈帧出栈
*/

void test3() {
    printf("test3 before.\n");
    printf("test3 after.\n");
}
void test2() {
    printf("test2 before.\n");
    test3();
    test3();
    printf("test2 after.\n");
}
void test1() {
    printf("test1 before.\n");
    test2();
    test3();
    printf("test1 after.\n");
}

int main(void) {
    printf("main before.\n");
    test1();
    test2();
    printf("main after.\n");
    return 0;
}