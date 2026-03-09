#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1.键盘输入一名学生的语文、数学和英语成绩（均为整数百分制）。计算其平均成绩，并保留两位小数打印显示。
2.键盘输入一个位于(0, 1)范围内的浮点数，并将其转化为百分比形式，结果保留一位小数。例如：输入0.12转换为12.0%，而输入0.1234转换为12.3%。
*/

/*
//题一
int main(void) {
    int Chinese_score = 0, Math_score = 0, English_score = 0;
    double average_score = 0.00;

    printf("请按顺序输入一名学生的语文、数学和英语成绩（用空格隔开）：\n");
    scanf("%d %d %d", &Chinese_score, &Math_score, &English_score);

    average_score = (Chinese_score + Math_score + English_score) / 3.0;
    printf("该学生的平均成绩为：%.2f\n", average_score);

    return 0;
}
*/

//题二
int main() {
    double num;

    printf("请输入一个 (0, 1) 之间的浮点数: ");
    scanf("%lf", &num);

    if (num <= 0 || num >= 1) {
        printf("输入错误，请输入一个在 0 到 1 之间的数字。\n");
        return 1;
    }

    // %.1f 表示保留一位小数
    // %% 是因为在 printf 中 % 是转义字符，需要两个 % 才能输出一个真实的百分号
    printf("转换结果为: %.1f%%\n", num * 100);

    return 0;
}