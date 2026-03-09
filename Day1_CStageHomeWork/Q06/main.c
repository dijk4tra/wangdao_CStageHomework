#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，根据输入的成绩（0-100之间的整数）输出相应的等级。

等级划分规则：
- 90分及以上：优秀
- 80-89分：良好
- 70-79分：中等
- 60-69分：及格
- 60分以下：不及格

要求：
1. 使用scanf()接收用户输入的成绩
2. 使用if-else多分支结构（级联式if语句）判断成绩等级
3. 如果输入的成绩不在0-100范围内，输出"输入成绩无效！"
4. 输出格式为："成绩等级: X"，其中X是相应的等级
*/

//级联式：所有的 if 和 else if 都在同一个层级
int main(void) {
	int score;
	printf("请输入成绩（（0-100之间的整数））：");
	scanf("%d", &score);

	if (score < 0 || score > 100) {
		printf("输入成绩无效！");
	}
	else if (score >= 90) {
		printf("成绩等级：优秀");
	}
	else if (score >= 80) {
		printf("成绩等级：良好");
	}
	else if (score >= 70) {
		printf("成绩等级：中等");
	}
	else if (score >= 60) {
		printf("成绩等级：及格");
	}
	else {
		printf("成绩等级：不及格");
	}

	return 0;
}


/*
// 嵌套式：在第一个 else 里面又套了一层完整的 if-else 结构
int main(void) {
	int score;
	printf("请输入成绩（0-100）：\n");
	scanf("%d", &score);

	if (score < 0 || score>100) {
		printf("输入成绩无效！\n");
	}
	else {
		if (score >= 90) {
			printf("成绩等级: 优秀\n");
		}
		else if (score >= 80) {
			printf("成绩等级: 良好\n");
		}
		else if (score >= 70) {
			printf("成绩等级: 中等\n");
		}
		else if (score >= 60) {
			printf("成绩等级: 及格\n");
		}
		else {
			printf("成绩等级: 不及格\n");
		}
	}
	return 0;
}

*/

