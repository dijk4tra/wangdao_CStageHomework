#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "test1.h"
#include "test2.h"

int main(void) {
    // 头文件一多，就容易出现撞车的情况，所以我们需要头文件保护性语法
    // 如果引入了一次，就不用引入第二次

    struct  student s1;

    return 0;
}