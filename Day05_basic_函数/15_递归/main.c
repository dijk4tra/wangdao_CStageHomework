#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n) {
    // 1+2+3+4+5+6+7+……+n
    // 递归最需要注意的点是：一定要注意递归的出口，即什么时候不再自己调用自己了
    if (n == 1 || n == 0) {
        // n == 1 返回1
        // n == 0 返回0
        return n;
    }
    // 要算 sum(n - 1) + n
    return sum(n - 1) + n;
}

int sum2(int n) {
    if (n == 1 || n == 0) {
        return n;
    }
    return n + sum(n - 1);
}

int main(void) {
    printf("sum(5) = %d\n",sum(5));
    printf("sum(5) = %d\n", sum(10));

    // 递归的基础使用
    // 递归的特点是：代码非常的简洁
    // 递归的问题：因为递归是使用函数调用自己，使用了栈来存储这个过程
    // 比较容易占用比较大的函数调用栈，栈可能会在这个过程中崩溃掉

    // 递归可能会存在大量的重复计算


    return 0;
}