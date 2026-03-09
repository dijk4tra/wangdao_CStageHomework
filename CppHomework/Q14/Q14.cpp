#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	float score, sum = 0;
	int higt_count = 0; //记录大于等于80分的学生人数
	int fail_count = 0; //记录不及格的学生人数

	printf("请依次输入10个学生的成绩：\n");
	for (int i = 0; i < 10; i++) {
		scanf("%f", &score);
		sum = sum + score; //累计总分
		if (score >= 80) higt_count++;
		if (score < 60) fail_count++;
	}

	printf("大于等于80分的学生人数: %d\n", higt_count);
	printf("不及格的学生人数: %d\n", fail_count);
	printf("平均分: %.2f\n", sum / 10);

	return 0;
}


/*
#include <stdio.h>

int main(){
	float score,sum = 0;
	int high_count = 0;
	int fail_count = 0;

	printf("请依次输入10个学生的成绩：\n")
	for(int i=0;i<10;i++){
		scanf("%f",&score);
		sum += score;
		if (score>=80) high_count++;
		if (score<60) fail_count++;
	}

	printf("大于等于80分的学生人数: %d\n",high_count);
	printf("不及格的学生人数: %d\n", fail_count);
	printf("平均分：%.2f", sum/10);

	return 0;
}

*/