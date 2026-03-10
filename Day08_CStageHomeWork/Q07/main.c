#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
定义一个Date结构体，包含年、月、日数据项。编写一个函数，计算两个日期之间的天数差。
不考虑平年闰年，不考虑月份天数不同。
假设每个月都是30天，每年是360天，以简化计算。
*/

// 定义Date结构体
struct Date{
    int year;
    int month;
    int day;
};

// 计算两个日期之间的天数差：将日期转换为自“公元0年”以来的总天数，然后相减
long long calculate_two_days_difference(struct Date d1, struct Date d2) {

    // 使用 long long 防止年份过大时相乘溢出
    long long totalDays1 = (long long)d1.year * 360 + (d1.month - 1) * 30 + d1.day;
    long long totalDays2 = (long long)d2.year * 360 + (d2.month - 1) * 30 + d2.day;

    long long difference = totalDays1 - totalDays2;

    // 如果差值为负数，取绝对值
    if (difference < 0) {
        difference = -difference;
    }

    return difference;

}



int main(void) {
    struct Date date1, date2;

    printf("请输入第一个日期 (年 月 日): ");
    scanf("%d %d %d", &date1.year, &date1.month, &date1.day);

    printf("请输入第二个日期 (年 月 日): ");
    scanf("%d %d %d", &date2.year, &date2.month, &date2.day);

    // 调用函数计算差值
    long long diff = calculate_two_days_difference(date1, date2);

    printf("两个日期之间相差的天数为: %lld 天\n", diff);

    return 0;
}