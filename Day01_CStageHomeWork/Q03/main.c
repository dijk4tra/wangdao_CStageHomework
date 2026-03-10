#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个程序实现以下需求：
1.用户键盘录入一整行字符数据，包含数字和字母。
2.当用户按下回车键后结束数据录入。
3.请统计用户输入的一整行字符数据中，数字和字母分别有多少个。
*/

int main(void) {
    char c;
    int letter_count = 0;
    int number_count = 0;

    printf("请输入一行字符：\n");

    while (1) {
        c = getchar(); //依次读取字符
        if (c == '\n') {
            break; //遇到换行符（回车），结束循环
        }
        //判断是否为字母
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letter_count++;
        }
        //判断是否为数字
        else if (c >= '0' && c <= '9') {
            number_count++;
        }
    }

    printf("字母个数：%d\n", letter_count);
    printf("数字个数：%d\n", number_count);

    return 0;
}