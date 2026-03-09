#include <stdio.h>
#include <stdlib.h>

//八皇后问题：在8×8的国际象棋棋盘上放置8个皇后，使得任何两个皇后都不能相互攻击（不在同一行、同一列或同一对角线）

// 全局数组，存储每一行皇后的列位置
int result[8]; // result[i] = j 表示第i行皇后在第j列
// 检查在棋盘的第row行第col列放置皇后是否合法
int is_safe(int row, int col) {			// 检查已经放置的所有行（0到row-1行）
	for (int i = 0; i < row; i++) {		// 检查同列和两条对角线
		// result[i] == col: 检查同一列是否有皇后
		// abs(row - i) == abs(col - result[i]): 对角线检查，如果两个皇后的行差等于列差的绝对值，说明在同一对角线上
		if (result[i] == col || abs(result[i] - col) == abs(i - row)) {
			return 0; // 该位置不合法
		}
	}
	return 1; // 该位置合法
}
// 递归放置皇后
void place_queen(int row) {
	if (row == 8) {		
		// 打印当前找到的解决方案
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (result[i] == j) printf("Q "); // 皇后位置
				else printf(". ");				  // 空位置
			}
			printf("\n");
		}
		printf("\n");
		return;
	}
	for (int col = 0; col < 8; col++) { // 尝试在当前行的每一列放置皇后
		if (is_safe(row, col)) {	// 检查当前位置是否安全
			result[row] = col;		// 放置皇后
			place_queen(row + 1);	// 放置下一行皇后
			// 注意：这里不需要显式回溯（如result[row] = -1）
			// 因为下一次放置会覆盖当前位置，这就是隐式回溯
		}
	}
}

int main() {
	printf("八皇后问题解决方案：\n");
	place_queen(0); // 从第0行开始放置皇后
	return 0;
}
	