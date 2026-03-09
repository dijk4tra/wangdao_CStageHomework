#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 用于引入exit()函数

int global_operation_num = 0;

int add(int a, int b) {
    global_operation_num++;
    return a + b;
}
int subtract(int a, int b) {
    global_operation_num++;
    return a - b;
}

int multiply(int a, int b) {
    global_operation_num++;
    return a * b;
}

float divide(int a, int b) {
    global_operation_num++;
    return (float)a / b; // 强制类型转换以获取小数
}

int main(void) {
    int num1, num2;
    char operator;
    char is_end = 'y';

    while(is_end == 'y' || is_end == 'Y') {
        printf("请输入要计算的表达式（例如：5 + 3）： ");
        scanf("%d %c %d", &num1, &operator, &num2);
        while (getchar() != '\n');
        switch (operator) {
        case '+':
            printf("结果：%d\n", add(num1, num2));
            break;
        case '-':
            printf("结果：%d\n", subtract(num1, num2));
            break;
        case '*':
            printf("结果：%d\n", multiply(num1, num2));
            break;
        case '/':
            if (num2 == 0) {
                printf("除数不能为零！\n");
                exit(-1);
            }
            else {
                printf("结果：%.2f\n", divide(num1, num2));
            }
            break;
        default:
            printf("无效的运算符。\n");
            break;
        }
        printf("是否继续？（y/n）： ");
        scanf(" %c",&is_end);
        while (getchar() != '\n');
    }
    printf("总共执行的操作次数为：%d", global_operation_num);
    return 0;
}