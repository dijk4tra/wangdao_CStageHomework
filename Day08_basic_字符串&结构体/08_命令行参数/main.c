#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(int argc, char *argv[]) {

    // 在C程序在，我们是可以接收到外部给的参数的
    // 怎么接收？在main函数这里处理
    
    // main(void)表明不接收参数

    // main(int argc, char *argv[])
    // 第一个参数告诉你，传进来了几个参数；第二个参数告诉你，参数分别是什么

    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];
        printf("----------------%s\n", arg);
    }
    
    // 系统在处理的时候，如果你一个参数都不给。 
    // 在程序内部，是可以接受到一个参数的。 
    // argc = 1;  argv[0] 是程序的路径。

    
    return 0;
}