#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
定义一个枚举类型Month（别名），包含一年中12个月份的英文单词。并从一月份开始，为枚举成员分配一个从1开始的数字值。
例如：JANUARY=1，FEBRUARY=2，依此类推....
编写一个函数，接收Month类型的参数，返回该月份有多少天。
注意：
    1.不考虑平年闰年，2月份一律输出28天。
    2.不要把12个case分支做12个处理，那也太笨了！
    3.枚举值应当采用英文单词字母全部大写的命名风格，类似宏定义。
*/

typedef enum month{
    JANUARY = 1, // 指定从1开始，后续成员会自动递增
    FEBRUARY,    // 2
    MARCH,       // 3
    APRIL,       // 4
    MAY,         // 5
    JUNE,        // 6
    JULY,        // 7
    AUGUST,      // 8
    SEPTEMBER,   // 9
    OCTOBER,     // 10
    NOVEMBER,    // 11
    DECEMBER     // 12
} Month;

int get_days_in_month(Month month) {
    int days;

    switch (month) {
    // 2月为28天
    case FEBRUARY:
        days = 28;
        break;
    // 4、6、9、11月都是30天
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        days = 30;
        break;
    // 剩余的1、3、5、7、8、10、12月都是31天
    default:
        days = 31;
        break;
    }

    return days;
}



int main(void) {
    
    printf("2月的天数为：%d\n", get_days_in_month(FEBRUARY));

    printf("3月的天数为：%d\n", get_days_in_month(MARCH));

    printf("4月的天数为：%d\n", get_days_in_month(APRIL));

    return 0;
}