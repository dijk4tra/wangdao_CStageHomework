#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 包含 rand() 和 srand()
#include <time.h>   // 包含 time()

/*
编写一个C程序，实现一个简单的猜数字游戏。程序随机生成一个1-100之间的数字，用户有5次机会猜这个数字。

要求：
1. 使用rand()函数生成1-100之间的随机数
2. 使用while循环控制最多猜5次
3. 每次猜完后给出提示（猜大了、猜小了）
4. 如果猜对了，使用break语句跳出循环并输出恭喜信息
5. 如果5次都没猜对，输出正确答案

考点： while循环，break语句，随机数
*/
int main(void) {
    // 设置种子值，确保每次运行生成的数字不同
    srand(time(NULL));

    // 使用rand()函数生成1-100之间的随机数
    int target = rand() % 100 + 1; //rand() % 100 得到 0-99，加1后即为 1-100

    int guess = 0;      // 存储玩家输入的数字
    int attempts = 0;   // 记录猜测次数
    int max_attempts = 5; // 最大尝试次数

    printf("这是一个猜数字游戏！\n");
    printf("我已经准备好了一个1到100之间的数字，你只有%d次机会来猜。\n", max_attempts);

    // 使用while循环控制最多猜5次
    while (attempts < max_attempts) {
        attempts++;
        printf("\n这是第%d次尝试，请输入你猜的数字: \n", attempts);
        scanf("%d", &guess);

        // 如果猜对了，使用break语句跳出循环并输出恭喜信息
        if (guess == target) {
            printf("恭喜你猜对了！答案就是%d。\n", target);
            // 跳出循环
            break;
        }
        else if (guess > target) {
            printf("猜大了！\n"); //每次猜完后给出提示（猜大了、猜小了）
        }
        else {
            printf("猜小了！\n");
        }

        // 如果5次都没猜对，输出正确答案
        if (attempts == max_attempts) {
            printf("5次机会已用完。正确答案是: %d\n", target);
        }
        else {
            printf("你还剩%d次机会。\n", max_attempts - attempts);
        }
    }

    return 0;
}