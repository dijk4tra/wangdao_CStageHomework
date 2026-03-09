#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    // 编译会进行：
    // 1.语法检查，语义检查
    // 2.适当的代码优化，进行一些代码的同义替换

    int num = 10;
    // num *= 2;
    num <<= 1; // 编译时会将例如上行的代码替换为本行的代码(对于计算机来说更易理解和实现)

    printf("hello world!\n");
    return 0;
}