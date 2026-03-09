#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>
#define PI 3.14159

int main() {
	float r, h, base_area, volume;
	printf("请输入圆柱体的半径和高度（用空格隔开）：");
	scanf("%f %f", &r, &h);

	// 计算圆柱体的底面积和体积
	base_area = PI * r * r ;
	volume = base_area * h;

	printf("圆柱体的底面积为：%.2f\n", base_area);
	printf("圆柱体的体积为：%.2f\n", volume);
	return 0;
}
