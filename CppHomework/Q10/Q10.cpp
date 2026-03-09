#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

float FtoC(float f) {
	// 注意要使用5.0而不是5，否则会进行整数除法，结果为0
	return (f - 32) * 5.0 / 9.0;
}

int main() {
	float f;
	printf("请输入华氏温度：");
	scanf("%f", &f);

	float c = FtoC(f);
	printf("对应的摄氏温度为：%.2f\n", c);

	return 0;
}


/*
#include <stdio.h>

float FtoC(float f){
	//注意要使用5.0而不是5，否则会进行整数除法，结果为0
	return (f-32)*5.0/9.0;
}

int main(){
	float f;
	printf("请输入华氏温度：");
	scanf("%f",&f);
	float c = FtoC(f);
	printf("对应的摄氏温度为：%.2f\n",c);

	return 0;
}

*/