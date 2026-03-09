#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>     // 包含 srand 和 rand 函数
#include <time.h>       // 包含 time 函数，用于获取系统时间戳
#include <stdbool.h>    // 包含 bool 类型及其字面量 true/false

/*
现在有一副扑克牌，去掉大小王。请你写一个随机发牌程序，由用户指定发几张票，然后打印用户得到的手牌。
注：
扑克牌的花色（suit）有四种：梅花（Club）、方块（Diamond）、红心（Heart）、黑桃（Spade）
扑克牌的点数（point）有13种，2~10，J，Q，K，A
*/

int main(void) {
    // 花色数组
    const char suit_arr[4] = { 'C', 'D', 'H', 'S' };
    // 点数数组
    const char point_arr[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

    // 使用当前系统时间作为随机数种子，确保每次运行程序时得到的随机序列不同
    srand(time(NULL));
    
    int need_card_number;
    printf("请输入您需要的手牌数量：");
    scanf("%d", &need_card_number);

    // 定义一个布尔类型二维数组，记录所有牌是否已被发出
    // 因为同一点数和花色的牌只有一张，不可能被发两次
    bool alreadly_send_card[4][13] = { {0} };
    // 记录已成功发出的牌的数量
    int alreadly_send_card_count = 0;

    printf("发牌中……\n");
    printf("发牌中……\n");
    printf("发牌中……\n");
    printf("您的手牌是：\n");

    // 只要已成功发出的牌的数量还没有达到用户要求的数量，就继续发牌
    while (alreadly_send_card_count < need_card_number) {
        // 随机生成花色下标[0,3]
        int suit_arr_index = rand() % 4;
        // 随机生成点数下标[0,12]
        int point_arr_index = rand() % 13;

        if (alreadly_send_card[suit_arr_index][point_arr_index]) {
            // 说明这张牌已经被发过了，故跳过本次循环，重新生成随机数，重新发牌
            continue; 
        }
        // 打印发出的牌的花色和点数
        printf("%c%c    ", suit_arr[suit_arr_index], point_arr[point_arr_index]);
        // 标记该牌已发出
        alreadly_send_card[suit_arr_index][point_arr_index] = true;
        // 已发牌数+1
        alreadly_send_card_count++;
    }

    return 0;
}