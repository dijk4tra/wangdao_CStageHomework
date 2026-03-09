#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个程序，要求用户键盘录入十名学生的语文成绩(百分制)，然后存储在一个一维数组中。最后计算全班的平均成绩、最高分和最低分，并打印出来。
注意：
1.要求使用一个int数组来存放成绩，平均成绩保留2位小数。
2.如果你还不理解将数组作为参数传递的话，请不要提取函数，直接将所有代码写到main函数里。
*/
int main(void) {
    int score[10] = { 0 };
    int sum = 0;
    int max, min;
    double average_score;

    printf("请依次输入十名学生的语文成绩(0-100)：\n");

    for (int i = 0; i < 10; i++) {
        printf("请输入第 %d 名学生的语文成绩：", i + 1);
        scanf("%d", &score[i]);

        // 将所有学生的成绩累加，用于计算平均成绩
        sum = sum + score[i];

        if (i == 0) {
            // 用第一名学生的成绩初始化max和min
            max = score[0];
            min = score[0];
        }
        else {
            if (score[i] > max) {
                max = score[i];
            }
            if (score[i] < min) {
                min = score[i];
            }
        }
    }

    average_score = (double)sum / 10;

    printf("\n--- 统计结果 ---\n");
    printf("全班平均成绩：%.2f\n", average_score);
    printf("全班最高分：%d\n", max);
    printf("全班最低分：%d\n", min);
   
    return 0;
}