#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
编写函数实现以下功能：
    1.键盘录入一个正整数，请判断它是否是一个素数，然后控制台输出对应的结果。要对键盘录入的数据做参数校验，素数是一个大于1的自然数，它仅能被1和自身整除
    2.键盘录入两个整数：底(base)和幂指数(exponent)，计算base的exponent次幂，并打印输出对应的结果。（注意底和幂指数都可能是负数）
提示：求幂运算时，基础的思路就是先无脑把指数转换成正数，然后累乘，最后再根据指数是否是负数决定是否取倒数。
*/

void isPrime(){
    int num;
    printf("请输入一个正整数: ");
    if (scanf("%d", &num) != 1) {
        printf("输入非法，请输入数字。\n");
        return;
    }

    if (num <= 1) {
        printf("%d 不是素数（素数必须是大于1的自然数）。\n", num);
        return;
    }

    bool isPrime = true;
    int limit = (int)sqrt(num);
    for (int i = 2; i <= limit; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        printf("%d 是一个素数。\n", num);
    }
    else {
        printf("%d 不是素数。\n", num);
    }
}

void calculateThePower(){
    int base;
    int exponent;
    double result = 1.0;

    printf("请输入底数(base)和幂指数(exponent)(用空格隔开): ");
    if (scanf("%d %d", &base, &exponent) != 2) {
        printf("输入格式错误。\n");
        return;
    }

    if (base == 0 && exponent < 0) {
        printf("错误：0 的负数幂无意义。\n");
        return;
    }

    // 使用了 (long long)exponent 是为了防止 INT_MIN 溢出
    // int的取值范围（若int类型占4B）是 [-2^32, 2^32-1]
    // 如果用户输入的刚好是int的最小值，就会发生溢出
    long long abs_exponent = (exponent < 0) ? -((long long)exponent) : exponent;

    for (int i = 0; i < abs_exponent; i++) {
        result *= base;
    }

    if (exponent < 0) {
        result = 1.0 / result;
    }

    printf("%d 的 %d 次幂结果为: %lf\n", base, exponent, result);
}


int main(void) {
    //isPrime();
    calculateThePower();
    return 0;
}