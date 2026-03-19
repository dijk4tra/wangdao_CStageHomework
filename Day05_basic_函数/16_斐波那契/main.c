#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 0   1   1   2   3   5   8   13   21   34    55
    // 0   1   2   3   4   5   6   7    8    9     10
    // fib(n) =  fib(n-1) + fib(n-2) 

    // 递归出口是什么？

    // 如果到了下标为 0 或 1 就不再继续递归 
}

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}


int main(void) {

    printf("%d\n", fib(10));

    return 0;
}