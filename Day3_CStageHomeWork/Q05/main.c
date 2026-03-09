#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("请输入需要计算的表达式（例如：2026.2 + 2026.7）：");

    // scanf会返回成功读取到的变量数量
    // 需要读取两个数字和一个字符，期望返回值是3
    if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {    // 注意%c前要有空格！
        printf("Error：输入的表达式格式不合法！请重新输入。\n");
        return 1; 
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
        // 除法需要检查除数是否为0
        if (num2 == 0) {
            printf("Error：除数为0！请重新输入表达式。\n");
            return 1; // 异常退出程序
        }
        result = num1 / num2;
        break;
    default:
        // 处理不支持的运算符
        printf("Error：不支持该运算符'%c'！请重新输入表达式。\n", operator);
        return 1; // 异常退出程序
    }

    printf("计算的结果是：%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);

    return 0;
}