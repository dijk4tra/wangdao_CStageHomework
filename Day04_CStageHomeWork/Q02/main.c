#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
固定投资的初始资金是100元，用户先输入年利率（rate）和要投资的年份（years）
投资收益后的资产每年计算一次，随后此程序将打印此利率在投资年份内每年的资产总价值，和紧随其后的4个更高的利率（总计5个利率）下投资的总价值。
余额考虑复利，第一年的余额是(本金 + 本金 * 利率)，第二年则可以在第一年余额的基础上累加(本金 * 利率)。
*/
int main(void) {
    int rate;
    int years;
    printf("请输入年利率：");
    scanf("%d", &rate);
    printf("请输入要投资的年份：");
    scanf("%d", &years);
    printf("\n");
    
    printf("Years");
    for (int i = 0; i < 5; i++) {
        // 打印Years后的5个利率
        printf("  %9d%%", rate + i);  // %9d中的9表示会预留9个字符的位置；想要打印%，就必须写%%
    }
    printf("\n");

    double balance[5] = { 100.00,100.00,100.00,100.00,100.00 };
    for (int i = 1; i <= years; i++) {
        // 打印第一列的投资年数
        printf("  %d   ",i);
        for (int j = 0; j < 5; j++) {
            // 计算5种利率下的第i年时的余额，并打印
            balance[j] = balance[j] + balance[j] * (rate + j) * 0.01;
            printf("%12.2lf", balance[j]);
        }
        printf("\n"); //换行
    }

    return 0;
}