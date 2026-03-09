#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>
#include <math.h> // 需要用到 sqrt

int main() {
	float a, b, c;
	printf("请输入三角形的三条边长（用空格隔开）：");
	scanf("%f %f %f", &a, &b, &c);
	// 判断是否能构成三角形
	if (a + b > c && a + c > b && b + c > a) {
		//计算该三角形的面积（海伦公式）
		float p = (a + b + c) / 2; // 半周长
		float area = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("该三角形的面积为：%.2f\n", area);
		//判断该三角形的类型
		if (a == b && b == c) {
			printf("该三角形是等边三角形。\n");
		}
		else if (a == b || b == c || a == c) {
			printf("该三角形是等腰三角形。\n");
		}
		else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
			printf("该三角形是直角三角形。\n");
		}
		else {
			printf("该三角形是普通三角形。\n");
		}
	}
	else {
		printf("输入的边长不能构成三角形！\n");
	}
	return 0;
}



/*
#include <stdio.h>
#include <math.h>

int main(){
	float a,b,c;
	printf("请输入三角形的三条边长（用空格隔开）：");
	scanf("%f %f %f",a,b,c);

	//判断是否能构成三角形
	if(a+b>c && a+c>b && b+c>a){
		//计算该三角形的面积（海伦公式）
		float p=(a+b+c)/2; //半周长
		float area=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("该三角形的面积为：%.2f\n",area);
		//判断该三角形的类型
		if (a==b && b==c) printf("该三角形是等边三角形。\n");
		else if (a==b || b==c || c==a ) printf("该三角形是等腰三角形。\n");
		else if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) printf("该三角形是直角三角形。\n");
		else printf("该三角形是普通三角形。\n");
	}
	else printf("输入的边长不能构成三角形！\n");
	return 0;
}

*/