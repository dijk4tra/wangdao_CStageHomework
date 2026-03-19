#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void test1() {
	// 生成随机数后，花色和点数的问题。 
	const char suit_arr[4] = { 'C', 'D','H', 'S' };

	int random_suit_index = rand() % 4;   // 0  1  2   3

	suit_arr[random_suit_index];
}

void test2() {
	// 第一次掷的时候：
	//   如果点数之和为 7 或 11 则获胜；
	//   如果点数之和为2、3或12则落败；
	//   其他情况下的点数之和称为“目标”，继续投掷两个骰子。
	// 在后续的投掷中：
	//   如果玩家再次掷出“目标”点数则获胜；
	//   如果掷出7则落败；
	//   其他情况都忽略，继续投掷两个骰子。
	// 在每一局游戏结束时，程序都要询问用户是否再玩一次，
	// 如果用户输入的回答不是 y 或 Y ，那么就结束游戏，程序此时要打印显示胜败的次数。
	
	srand(time(NULL));

	int win_count = 0;
	int lose_count = 0;
	char input_flag = 'y';

	while (input_flag == 'y' || input_flag == 'Y') {
		int dice1 = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;
		int first_roll_sum = dice1 + dice2;
		bool has_res = false;

		printf("You rolled: %d\n", first_roll_sum);
		if (first_roll_sum == 7 || first_roll_sum == 11) {
			printf("You win!\n");
			win_count++;
			has_res = true;
		}
		else if (first_roll_sum == 2 || first_roll_sum == 3 || first_roll_sum == 12) {
			printf("You lose!\n");
			lose_count++;
			has_res = true;
		}

		printf("Your point is %d\n", first_roll_sum);
		while (!has_res) {
			dice1 = rand() % 6 + 1;
			dice2 = rand() % 6 + 1;
			int next_roll_sum = dice1 + dice2;
			printf("You rolled: %d\n", next_roll_sum);
			if (next_roll_sum == first_roll_sum) {
				printf("You win!\n");
				win_count++;
				has_res = true;
			}
			else if (next_roll_sum == 7) {
				printf("You lose!\n");
				lose_count++;
				has_res = true;
			}
		}

		printf("Play again?(y/Y means continue) ");
		// 用scanf接受字符输入时要注意，%c前面要加空格！可以避免读取到空格、回车等
		scanf(" %c", &input_flag);
		// 接受scanf输入后要用getchar清空stdin中的剩余内容，防止用户输入yyy、yes等情况
		while (getchar() != '\n');

	}
	printf("Wins: %d     Losses: %d\n", win_count, lose_count);

}





int main(void) {
	test2();

	return 0;
}