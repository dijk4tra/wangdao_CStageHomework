#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    printf("test1\n");
}

void test2();
// 此处仅仅声明了函数test2，并未定义函数
// 在编译的过程中，编译器并不会检查调用的某个函数是否真正定义(即函数是否有真正的实现)，最多只会检查它是否存在声明
// 若没有test.c存在（其中定义了函数test2），则会在链接阶段中报错，因为链接器无法真正将函数的定义(实现)合并到目标文件中

int main(void) {
    test1();
    test2();
    return 0;
}