#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "test1.h"
#include "test1.h"

// #ifndef 是一个预处理指令
// #ifndef：if not define
// 如果没有这个宏定义，就将if---end直接的内容复制过去
// 如果有这个宏定义，就不复制粘贴过去


int main(void) {
    printf("main =======.\n");

    // 系统的头文件中，也有头文件保护语法
    // 所以后期，我们写的头文件中，基本都会加上这个头文件保护性语法

    return 0;
}