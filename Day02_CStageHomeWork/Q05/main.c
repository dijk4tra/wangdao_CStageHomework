#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h> // 使用 bool 类型必须包含此头文件

/*
用C语言编写程序实现以下需求：
编写一个函数，输入一个公元年份（如2004），判断该年是否为闰年，并返回判断结果。
平年闰年的规则如下：
    1.如果年份不是4的倍数，则是平年。
    2.如果年份是4的倍数但不是100的倍数，则是闰年。
    3.如果年份是100的倍数但不是400的倍数，则是平年。
    4.如果年份是400的倍数，则是闰年。
要求使用bool类型作为函数的返回值。
*/

// 函数：判断是否为闰年
bool isLeapYear(int year) {
    // 闰年：能被4整除且不能被100整除 或者 能被400整除
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;  // 是闰年
    }
    else {
        return false; // 是平年
    }
}

int main() {
    int inputYear;

    printf("请输入一个年份: ");
    scanf("%d", &inputYear);

    if (isLeapYear(inputYear)) {
        printf("%d 年是闰年。\n", inputYear);
    }
    else {
        printf("%d 年是平年。\n", inputYear);
    }

    return 0;
}