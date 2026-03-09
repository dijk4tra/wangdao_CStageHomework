#include <stdio.h>

double calculateSum(int n) {
	double sum = 0.0;  // 初始化和为0，使用double保证精度
	for (int i = 1; i <= n; i++) {
		// 关键点：必须使用 1.0 而不是 1，确保进行浮点数除法
		// 如果使用 1/(2*i)，整数除法会截断小数部分，结果始终为0
		sum += 1.0 / (2 * i);  // 累加每一项
	}
	return sum;  // 返回最终的和
}

int main() {
	int n = 20;  // 设置要计算的项数
	double result = calculateSum(n);  // 调用函数计算结果
	printf("前%d项的和为：%f\n", n, result);

	return 0;
}