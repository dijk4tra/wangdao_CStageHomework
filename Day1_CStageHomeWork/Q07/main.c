#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，根据输入的数字（1-7）输出对应的星期几。

对应关系：
- 1: 星期一
- 2: 星期二
- 3: 星期三
- 4: 星期四
- 5: 星期五
- 6: 星期六
- 7: 星期日

要求：
1. 使用scanf()接收用户输入的数字
2. 使用switch语句进行转换
3. 如果输入的数字不在1-7范围内，输出"输入错误！"
4. 每个case分支都要有break语句
*/


int main(void) {
    int day;
    printf("请输入数字 (1-7): \n");
    scanf("%d", &day);
    switch (day) {
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期日\n");
        break;
    // 输入的数字不在1-7范围内
    default:
        printf("输入错误！\n");
        break;
    }

    return 0;
}

/*
int main(void) {
    int day = 0;
    printf("请输入数字（1-7）：\n");
    scanf("%d", &day);
    switch (day) {
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期日\n");
        break;
    // 输入的数字不在1-7的范围内
    default:
        printf("输入错误！\n");
        break;
    }
    return 0;
}
*/