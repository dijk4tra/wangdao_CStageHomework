#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，实现一个简单的计算器，可以进行加、减、乘、除四则运算。

要求：
1. 使用do-while循环实现重复计算
2. 显示菜单让用户选择操作
3. 使用switch语句处理不同的运算
4. 输入0退出程序
5. 除法运算要检查除数是否为0
*/

int main(void) {
    int choice;          // 用户选择的操作
    double num1, num2;   // 操作数
    double result;       // 运算结果

    do {
        // 显示菜单让用户选择操作
        printf("\n------ 简单计算器 ------\n");
        printf("1.加法\n");
        printf("2.减法\n");
        printf("3.乘法\n");
        printf("4.除法\n");
        printf("0.退出程序\n");
        printf("请选择操作（输入相应数字即可）: ");
        scanf("%d", &choice);

        // 如果用户选择退出，直接跳过后面的输入和运算
        if (choice == 0) {
            printf("计算器已关闭\n");
            break;
        }

        // 检查输入是否合法
        if (choice < 0 || choice > 4) {
            printf("输入错误，请重新选择！\n");
            continue;
        }

        // 获取操作数
        printf("请输入两个数字（用空格隔开）: ");
        scanf("%lf %lf", &num1, &num2);

        // 使用switch语句处理不同的运算
        switch (choice) {
        case 1:
            result = num1 + num2;
            printf("运算结果: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("运算结果: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("运算结果: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            // 除法检查：除数不能为 0
            if (num2 == 0) {
                printf("错误：除数不能为零！\n");
            }
            else {
                result = num1 / num2;
                printf("运算结果: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        }
    } while (choice != 0); // 使用do-while循环实现重复计算

    return 0;
}