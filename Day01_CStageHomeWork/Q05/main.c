#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，从键盘输入两个整数，使用三目运算符找出并输出这两个数中的最大值。
要求：
1. 使用scanf()函数接收用户输入的两个整数
2. 使用三目运算符?:来比较两个数的大小
3. 输出格式为："最大值是: X"，其中X是找到的最大值
*/

int main(void) {
    int x = 0, y = 0;
    printf("请输入两个数字（用空格隔开）：\n");
    scanf("%d %d", &x, &y);
    int max = (x > y) ? x : y; // 如果 x > y 为真，则值取 x，否则取 y
    printf("最大值为：%d\n", max);
    return 0;
}

/*
int main(void) {
    int x = 0, y = 0;
    printf("请输入两个整数（用空格隔开）：\n");
    scanf("%d %d", &x, &y);
    int max = (x > y) ? x : y; // 如果 x > y 为真，则值取 x，否则取 y
    printf("最大值是: %d", max);
    return 0;
}
*/