#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void test1() {
    // 比如，要生成[50,100]的随机数
    srand(time(NULL));

    //rand() % (50); // [0,49] + 50 ==> [50, 99]
    rand() % (51); // [0,50] + 50 ==> [50, 100]

    // 要生成在[a,b]范围内的随机数，公式如下
    // rand() % （b-a+1） + a;
}

void test2() {
    // 扑克牌的花色（suit）有四种：梅花（Club）、方块（Diamond）、
    // 红心（Heart）、黑桃（Spade）
    // 扑克牌的点数（point）有13种，2~10，J，Q，K，A

    // 解题思路：随机数 + 固定的数组
    // 从这个数组中，随机取出来东西（扑克牌）
    
    const char suit_arr[4] = { 'C','D','H','S' };
    // '10' 则是由两个字符（'1' 和 '0'）组成的字符串，无法塞进一个 char 变量里，故用 'T' 代替 '10'
    const char point_arr[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };

    srand(time(NULL));

    int random_suit_index = rand() % 4;    // 得到[0,3]中的随机数
    int random_point_index = rand() % 13;  // 得到[0,12]中的随机数
}

void test3() {
    const char suit_arr[4] = { 'C','D','H','S' };

    const char point_arr[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };

    srand(time(NULL));

    int need_card_number;
    printf("Please inpit the card_number you need: \n");
    scanf("%d", &need_card_number);

    bool already_send_card[4][13] = { {0} };  // 注意：二维数组是存储一维数组的数组！

    for (int i = 0; i < need_card_number; i++) {
        int random_suit_index = rand() % 4;
        int random_point_index = rand() % 13;

        if (already_send_card[random_suit_index][random_point_index]) {
            // 说明这张牌已经发过了
            printf("%c%c重复发送了\n", suit_arr[random_suit_index], point_arr[random_point_index]);
            i--;
            continue;
        }

        printf("%c%c\n", suit_arr[random_suit_index], point_arr[random_point_index]);
        already_send_card[random_suit_index][random_point_index] = true;
    }
}


void test4() {
    const char suit_arr[4] = { 'C', 'D', 'H', 'S' };
    const char point_arr[13] = { '2', '3', '4', '5', '6', '7', '8', '9',
        'T', 'J', 'Q', 'K', 'A' };

    srand(time(NULL));

    int need_card_number;
    printf("Please inpit the card_number you need: \n");
    scanf("%d", &need_card_number);

    bool already_send_card[4][13] = { {0} };

    int already_send_card_count = 0;

    while (already_send_card_count < need_card_number) {
        int random_suit_index = rand() % 4;
        int random_point_index = rand() % 13;

        if (already_send_card[random_suit_index][random_point_index]) {
            // 说明这张牌已经发过了
            continue;
        }

        printf("%c%c\n", suit_arr[random_suit_index], point_arr[random_point_index]);
        already_send_card[random_suit_index][random_point_index] = true;
        already_send_card_count++;
    }
}

void test5() {
    // 猜大小。 0-100   
    srand(time(NULL));

    int random_value = rand() % 100;

    // 只能猜5次。 
    int already_guess_count = 0;
    int max_guess_count = 5;

    while (true) {
        printf("guess numer: \n");
        int guess_numer;
        scanf("%d", &guess_numer);

        if (guess_numer == random_value) {
            // 说明猜对了。 
            printf("guess right, number=%d\n", random_value);
            break;
        }
        else if (guess_numer < random_value) {
            printf("guess low\n");
        }
        else {
            printf("guess high\n");
        }

        already_guess_count++;
        if (already_guess_count >= max_guess_count) {
            printf("guess over max_count random_value=%d.\n", random_value);
            break;
        }
    }
}


int main(void) {
    //test2();
    //test3();
    test4();
    //test5();
    return 0;
}