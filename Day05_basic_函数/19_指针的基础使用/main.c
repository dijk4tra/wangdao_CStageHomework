#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 在C语言中，指针就是地址，指针可以存储一个变量的地址

    int num = 10;

    // 现在，想使用一个指针，指向这个int类型的变量num
    // 指针 名字 = &num;

    // 指针，分两块记忆：1.声明的时候；2.其他时候
    // 声明的时候纯粹表示这是一个指针
    int* p1 = &num; // 声明

    //使用
    printf("%d\n", *p1); //这里的*p1就是去变量p1保存的地址处去取数
    *p1 = 8888; // 这里是将8888这个数，存到变量p1保存的地址处

    printf("%d\n", *p1);
}

void test2() {
    // int num = 100;
    // num是一个变量，存储在一个位置，占4个字节
    // p1叫做指针变量，它也是一个变量，这个变量中存的是地址
    // p1自己也会占据一块空间 
    // 指针变量里面存储的是，别人的地址
    // int *p1 = &num;
}

int main(void) {
    test1();

    return 0;
}