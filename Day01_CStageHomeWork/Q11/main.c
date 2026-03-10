#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，要求用户输入5个整数，计算其中所有非负整数（大于等于0）的和。

要求：
1. 使用for循环接收5次输入
2. 使用continue语句跳过负数（小于0的数）
3. 只累加非负整数
4. 输出格式为："非负整数的和是: %d"
*/

int main(void) {
    int num; // 存储每次输入的整数
    int sum = 0; // 所有非负整数的和
    int i;
    
    printf("请输入5个整数：\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &num);
        if (num < 0) {
            continue; //使用continue语句跳过负数
        }
        sum += num; //只累加非负整数
    }

    printf("非负整数的和是: %d\n", sum);
    return 0;
}