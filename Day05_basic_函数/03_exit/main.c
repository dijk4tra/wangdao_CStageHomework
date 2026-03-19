#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
    printf("test1---before.\n");

    exit(0); // 与return 0;等价
    //exit(EXIT_SUSSESS);

    //exit(1);
    //exit(EXIT_FAILURE);

    // 代码为0，代码为1，表明程序是否正常退出

    printf("test1---after.\n");

}

void test2() {
    // exit 在什么时候使用？在学习阶段可以使用
    // 不建议在公司中使用exit
}

int main(void) {
    test1();
    return 0;
}