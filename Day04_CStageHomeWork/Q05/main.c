#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 包含 srand() 和 rand() 函数
#include <time.h>   // 包含 time() 函数，用于获取系统时间戳

/*
编写程序模拟掷骰子的游戏（每一次投掷，都投掷两个骰子）。每局游戏的规则如下：
第一次掷的时候：
    如果点数之和为 7 或 11 则获胜；
    如果点数之和为2、3或12则落败；
    其他情况下的点数之和称为“目标”，继续投掷两个骰子。
在后续的投掷中：
    如果玩家再次掷出“目标”点数则获胜；
    如果掷出7则落败；
    其他情况都忽略，继续投掷两个骰子。
在每一局游戏结束时，程序都要询问用户是否再玩一次，如果用户输入的回答不是 y 或 Y ，那么就结束游戏，程序此时要打印显示胜败的次数。

提示（请思考三个问题）：
1.肯定需要使用随机数，那么srand设置种子值，这个函数调用应该放在哪里呢？
2.在键盘录入是否继续游玩时，如果键盘输入的是"(空格)y"，会发生什么事情？怎么解决？
3.在键盘录入是否继续游玩时，如果键盘输入的是"yyy"，会发生什么事情？怎么解决？
*/

// 掷骰子函数：返回两个骰子的点数之和
int roll_dice() {
    // rand()%6 会生成[0,5]的随机数
    // rand()%6+1 则生成[0,6]的随机数，刚好可模拟骰子
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;
    int sum = dice1 + dice2;
    printf("You rolled: %d\n", sum);
    return sum;
}


int main(void) {
    // 传入当前时间戳作为种子，保证每次运行程序时，骰子的结果序列都不一样
    // srand(time(NULL));需要放在main函数开头，千万不能放在循环中
    // 否则由于程序运行极快，每次获取的系统时间可能相同，导致最后生成的“随机数”序列完全一样
    srand(time(NULL));
    // 记录胜败次数
    int win_count = 0;
    int lose_count = 0;
    // 用于接收用户是否再玩一局的输入
    char play_again;

    do {
        // 第一次投掷
        // 点数之和为 7 或 11 则获胜
        // 点数之和为2、3或12则落败
        printf("Roll 1: \n");
        int sum = roll_dice();
        if (sum == 7 || sum == 11) {
            printf("You win!\n");
            win_count++;
        }
        else if(sum == 2 || sum == 3 || sum == 12) {
            printf("You lose!\n");
            lose_count++;
        }
        else {
            // 后续投掷
            // 再次掷出“目标”点数（第一次投掷的点数）则获胜，掷出7则落败
            int target_point = sum;
            int game_over = 0;
            int roll_number = 2;
            printf("Your point is %d\n", target_point);
            while (game_over == 0) {
                printf("Roll %d: \n", roll_number);
                sum = roll_dice();
                roll_number++;
                if (sum == target_point) {
                    printf("You win!\n");
                    win_count++;
                    game_over = 1;
                }
                else if (sum == 7) {
                    printf("You lose!\n");
                    lose_count++;
                    game_over = 1;
                }
            }
        }
        printf("\nPlay again?(y/Y means continue) ");
        // %c前面加空格空格相当于告诉scanf忽略所有在前面的空白字符（空格、回车等），直接去获取第一个非空白字符
        // 这样可以避免用户错误输入"(空格)y"的情况
        scanf(" %c", &play_again);
        // 每次读取用户输入后，必须清理输入缓冲区（处理错误输入了类似yyy、yes情况）
        // 否则这些多余的字符会被下一次循环的 scanf 错误读取
        while (getchar() != '\n');
        printf("\n");

    } while (play_again == 'Y' || play_again == 'y');

    printf("Wins: %d   Losses: %d", win_count, lose_count);

    return 0;
}