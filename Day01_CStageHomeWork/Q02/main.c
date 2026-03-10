#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
键盘输入一名学生的语文、数学和英语成绩（均为整数百分制）。计算其平均成绩，并保留两位小数打印显示。
*/

int main(void) {
    int Chinese_score = 0, Math_score = 0, English_score = 0;
    double average_score = 0.00;

    printf("请按顺序输入一名学生的语文、数学和英语成绩（用空格隔开）：\n");
    scanf("%d %d %d", &Chinese_score, &Math_score, &English_score);

    average_score = (Chinese_score + Math_score + English_score) / 3.0;
    printf("该学生的平均成绩为：%.2f\n", average_score);

    return 0;
}