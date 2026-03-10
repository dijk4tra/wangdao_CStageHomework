#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    double account_balance = 0.0; // 账户余额，初始为0
    int user_choice;           // 用户的菜单选择
    double amount;        // 每次存/取款的金额
    
    // 使用while循环让程序持续运行，直到用户主动退出
    while (1) {
        // 打印菜单
        printf("\n======= 记账程序菜单 =======\n");
        printf("0. 清空账户余额\n");
        printf("1. 往账户上存钱\n");
        printf("2. 从账户上取钱\n");
        printf("3. 显示当前余额\n");
        printf("4. 退出程序\n");
        printf("请选择操作 (0-4) : ");
        // 读取用户选择
        scanf("%d", &user_choice);
        // 根据用户的选择执行对应的操作
        switch (user_choice) {
        
        case 0:
            account_balance = 0.0;
            printf("账户余额已清空。\n");
            break;
        case 1:
            printf("请输入存款金额: ");
            scanf("%lf", &amount);
            // 简单的输入验证，确保存款不能是负数
            if (amount > 0) {
                account_balance += amount;
                // %.2f 表示保留两位小数输出
                printf("成功存款 %.2f 元。\n", amount);
            }
            else {
                printf("金额输入错误，存款失败。\n");
            }
            break;
        case 2:
            printf("请输入取款金额: ");
            scanf("%lf", &amount);
            // 取款时需要验证两点：金额必须大于0，且不能超过当前余额
            if (amount > 0 && amount <= account_balance) {
                account_balance -= amount;
                printf("成功取款 %.2f 元。\n", amount);
            }
            else if (amount > account_balance) {
                printf("余额不足！当前余额为 %.2f 元。\n", account_balance);
            }
            else {
                printf("金额输入错误，取款失败。\n");
            }
            break;
        case 3:
            printf("当前余额: %.2f 元\n", account_balance);
            break;
        case 4:
            printf("记账程序已退出。\n");
            return 0; 
        default:
            // 处理用户输入0-4以外数字的情况
            printf("无效的选择，请重新输入。\n");
            break;
        }
    }

    return 0;
}