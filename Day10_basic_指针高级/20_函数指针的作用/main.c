#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void compute_and_show(int num1, int num2, int ptr1(int, int)) {
    printf("compute result = %d\n", ptr1(num1, num2));
}

int sum(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

void test2() {
    compute_and_show(10, 20, sum);
    compute_and_show(10, 20, sub);
    compute_and_show(10, 20, mul);

    // 函数指针是用来传递函数的，就是在为后续的扩展留下可能
}

void test1() {
    // 函数指针的作用：就是一个指针，指向函数
    // 传递这个指针，就等价于传递这个函数

    // 传递函数有什么作用？
    // 可以在不改动代码的情况下，传进自己的特定逻辑
}


int main(void) {

    test2();

    return 0;
}