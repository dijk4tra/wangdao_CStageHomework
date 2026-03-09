#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	int matrix[3][3];
	int sum = 0;

	printf("请输入一个3x3的矩阵的九个元素（用空格隔开）：\n");
	// 输入矩阵元素
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	// 计算主对角线元素之和
	for (int i = 0; i < 3; i++){
		sum += matrix[i][i];	//主对角线元素的行标和列标相同
	}
	printf("主对角线元素之和为: %d\n", sum);
	return 0;
}



/*
#include <stdio.h>

int main(){
	int matrix[3][3];
	int sum = 0;

	//输入矩阵元素
	printf("请输入一个3x3的矩阵的九个元素（用空格隔开）：\n");
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			scanf("%d",&matrix[i][j]);
	}

	//计算主对角线元素之和
	for (int i=0;i<3;i++){
		sum += matrix[i][i]; //主对角线元素的行标和列标相同
	}

	printf("主对角线元素之和为：%d",sum);
	return 0;
}
*/