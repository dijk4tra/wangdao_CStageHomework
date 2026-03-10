#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
编写一个函数isPrime()，判断一个整数是否为素数（质数），然后在主函数中测试。

要求：
1. 编写一个函数int isPrime(int num)，如果num是素数返回1，否则返回0
2. 在主函数中调用该函数测试几个数字
3. 素数定义：大于1的自然数，除了1和它本身外，不能被其他自然数整除
4. 使用for循环和break语句优化判断过程
5. 使用return语句提前返回结果
*/



// 判断一个整数是否为素数（质数）
int isPrime(int num) {
    // 素数的定义：必须是大于1的自然数
    if (num <= 1) {
        return 0; 
    }

    // 只需要循环到该数的平方根即可
    // 因为如果一个数能被分解为两个因数，其中一个必定小于或等于它的平方根
    int limit = (int)sqrt(num);

    for (int i = 2; i <= limit; i++) {
        if (num % i == 0) {
            // 如果能被整除，说明不是素数
            return 0;
        }
    }
    // 如果整个循环结束都没有触发return 0，说明它是素数
    return 1;
}

int main(void) {
    // 测试几个数字
    int test_nums[] = { -6, 1, 2, 7, 13, 33 };
    int count = 6; // 数组中数字的个数

    printf("--- 开始素数测试 ---\n");

    for (int i = 0; i < count; i++) {
        int current_num = test_nums[i];

        // 根据返回值判断当前数字是否为素数
        if (isPrime(current_num) == 1) {
            printf("%d是素数\n", current_num);
        }
        else {
            printf("%d不是素数\n", current_num);
        }
    }

    return 0;
}