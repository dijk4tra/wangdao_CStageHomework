#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 函数返回值类型 函数名(形参列表){
// 函数体
// return 返回值
// }
int add(int num1, int num2) {
	printf("add------%d + %d\n", num1, num2);
	return num1 + num2;
}

void funct1(void) {
	printf("HelloWorld!");
}

void funct2(double num1, double num2) {
	double sum = num1 + num2;
	printf("两个双精度浮点数的和是: %f\n", sum);
}

int funct3(double a, double b, double c) {
	double total = a + b + c;
	return (int)total;
}

double funct4(int x, int y, int z) {
	// 注意：除以 3.0 是为了强制进行浮点数除法，保留小数部分
	return (x + y + z) / 3.0;
}

int main(void) {

	// 函数写好之后，只是定义了一个架子。但是不调用，是不会直接运行的。 
	int num333 = 789;
	int num444 = 100;
	//add(int num333, int num444);
	int res = add(num333, num444);

	// 写一个函数，没有入参，没有返回值的
	// 写一个函数，有两个double入参，没有返回值。 
	// 写一个函数，有三个double入参，返回int。  
	// 写一个函数，有三个int入参，返回double。   

	funct1();
	funct2(1.10,2.20);
	funct3(1.10,2.20,3.30);
	funct4(3,7,9);

	printf("%d\n", res);

	return 0;
}