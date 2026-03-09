#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1111() {
    printf("test111111=.\n");
}

void test1() {
    int num = 10;

    // func_ptr1：直接使用函数名，给一个函数指针初始化
    void (*func_ptr1)(void) = test1111;

    // 函数指针怎样使用： (*指针名)();
    (*func_ptr1)();
    func_ptr1();     // 推荐这种

    // *func_ptr1(); //这样写是不对的，小括号优先级高于*
}

void test2111(int num1, int num2) {
    printf("test2111==================.\n");
    return num1 + num2 + 100;
}

void test2222(int num1, int num2) {
    printf("test2222==================.\n");
    return num1 + num2 + 200;
}

void test2() {
    // 入参是两个int；返回值 int
    //int (*func_ptr1)(int, int) = test2111;
    int (*func_ptr1)(int, int) = test2222;

    int res = (*func_ptr1)(10, 20);
    printf("res = %d\n", res);
}

void test3() {
    int (*func_ptr1)(int, int) = test2111;

    int res = (*func_ptr1)(10, 20);
    printf("res = %d\n", res);

    func_ptr1 = test2222;
    int res2 = (*func_ptr1)(10, 30);
    printf("res2 = %d\n", res2);

    // 函数指针
}

typedef int (*FuncPtr)(int, int);
void test4() {
    printf("test44444444444\n");
    FuncPtr ptr1 = test2111;

    int res = (*ptr1)(10, 20);
    printf("res = %d\n", res);

    ptr1 = test2222;
    int res2 = (*ptr1)(10, 30);
    printf("res2 = %d\n", res2);

    // 函数指针
}


int main(void) {
    
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}