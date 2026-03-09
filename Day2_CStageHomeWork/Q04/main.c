#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
写一个程序，实现分数相加。用户以分子/分母的形式输入分数，程序打印相加后的结果(化为最简分数)
注：利用欧几里得算法求最大公约数，进行分数简化
*/

// 函数：计算最大公约数
int calculate_the_greatest_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int n1, d1, n2, d2; // 分子 (numerator) 和 分母 (denominator)
    int res_n, res_d;   // 结果的分子和分母

    // 使用 %d/%d 可以直接匹配输入的 "1/4" 这种格式
    printf("请输入第一个分数(分子/分母): ");
    scanf("%d/%d", &n1, &d1);
    printf("请输入第二个分数(分子/分母): ");
    scanf("%d/%d", &n2, &d2);

    // 通分相加
    res_n = n1 * d2 + n2 * d1;
    res_d = d1 * d2;

    // 约分
    int common = calculate_the_greatest_common_divisor(res_n, res_d);
    res_n /= common;
    res_d /= common;

    // 根据结果判断输出格式
    if (res_d == 1) {
        printf("两个分数的和是一个整数，即: %d\n", res_n);
    }
    else {
        printf("两个分数的和是一个分数，即: %d/%d\n", res_n, res_d);
    }

    return 0;
}