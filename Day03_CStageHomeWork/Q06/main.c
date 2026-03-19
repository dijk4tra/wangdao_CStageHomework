#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;
    char choice; // 循环控制变量

    do {
        printf("请输入需要计算的表达式（例如：2026.2 + 2026.7）：");

        if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
            printf("Error：输入的表达式格式不合法！请重新输入。\n");
            // 清空输入缓冲区，防止错误字符导致死循环
            while (getchar() != '\n');
            choice = 'y'; // 强制设置变量以继续循环
            continue;     // 跳过本次循环的剩余部分，重新开始
        }

        // 根据运算符执行不同的计算
        switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error：除数为0！请重新输入表达式。\n");
                choice = 'y'; // 强制继续
                continue;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error：不支持该运算符'%c'！请重新输入表达式。\n", operator);
            while (getchar() != '\n'); // 清空缓冲区
            choice = 'y';
            continue;
        }

        // 计算结果输出
        printf("计算的结果是：%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);

        // 询问用户是否继续
        printf("是否继续计算？(输入 'y/Y' 继续，其他任意键结束)：");
        scanf(" %c", &choice); // %c前面要多打一个空格，避免上次输入遗留的换行符

        // 清空输入缓冲区，避免用户输入yyyyy、yes等情况
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');

    printf("计算器已关闭。\n");
    return 0;
}