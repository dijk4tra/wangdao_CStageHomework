#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	float score, max = -1, min = 101; //假设分数在0-100之间
	int count = 0; // 记录是否输入有效分数

	printf("请输入学生成绩（当输入负数时结束）：\n");

	while (1) {
		scanf("%f", &score);
		if (score < 0) break; // 输入负数时结束
		//若第一个是有效分数，则初始化最大值和最小值
		if(count == 0){
			max = score;
			min = score;
		}
		else {
			if (score > max) max = score; //更新最大值
			if (score < min) min = score; //更新最小值
		}
		count++;
	}

	if (count > 0) printf("最高分: %.2f, 最低分: %.2f\n", max, min);
	else printf("未输入有效分数！\n");
	
	return 0;
}

/*
include <stdio.h>

int main(){
	float score, max=-1, min=101; //假设分数在0-100之间
	int count=0; //记录是否输入有效分数

	printf("请输入学生的成绩（当输入负数时结束）：\n")
	while(1){
		if (score < 0) break; //输入负数时结束
		if(count == 0){
			max = score;
			min = score;
		}
		else{
			if(score > max) max = score; //更新最大值
			if(score < min) min = score; //更新最小值
		}
		count++;
	}

	if (count > 0) printf("最高分：%.2f，最低分：%.2f\n",max,min);
	else printf("未输入有效分数！\n");
	return 0;
}
*/