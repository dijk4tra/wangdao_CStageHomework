#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 指针一定要进行初始化再使用
    int* p1;

    int num = 666;
    int* p2 = &num;

    // NULL是空指针，定义在stdio.h中
    // NULL其实就是0，换句话说，p3指向了地址0
    int *p3 = NULL;
    // 这个叫空指针，如果我们对p3进行操作，大多数的编译器会直接崩溃
    //printf("%d\n", *p3);
    *p3 = 999;
    printf("%d\n", *p3);
}

void test2() {
    int num1 = 10;
    int *p1 = &num1;
    // p1是一个指针，其值为num1的地址

    int *p2 = p1;   // p2是一个指针，将p1的值（num1）的地址给p2
    int *p3 = *p1;  // p3是一个指针，将p1指向的值取回来，p3指向10这个位置
    int *p4 = &p1;  // p4是一个指针，指向p1，即p4是二级指针
}


int main(void) {
    //test1();
    test2();

    return 0;
}