#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	float score;	// 此处假设分数不是纯整数
	printf("请输入成绩（0-100）：");
	scanf("%f", &score);

	if (score < 0 || score>100){
		printf("输入的成绩不在正确区间（0-100）内！\n");
	}
	else {
		if (score >= 90) {
			printf("A（优秀）\n");
		}
		else if (score >= 80) {
			printf("B（良好）\n");
		}
		else if (score >= 70) {
			printf("C（中等）\n");
		}
		else if (score >= 60) {
			printf("D（合格）\n");
		}
		else {
			printf("E（不合格）\n");
		}
	}
	return 0;
}

/*
#include <stdio.h>
int main(){
	float score;
	printf("请输入成绩（0-100）：");
	scanf("%f",&score);
	if (score<0 ||) score>100) printf("输入的成绩不在正确区间内！")；
	else{
		if(score>=90) printf("A（优秀）\n")；
		else if (score>=80) printf("B（良好）\n")；
		else if (score>=70) printf("C（中等）\n")；
		else if (score>=60) printf("D（合格）\n")；
		else printf("E（不合格）\n")；
	}
	return 0;
}
*/