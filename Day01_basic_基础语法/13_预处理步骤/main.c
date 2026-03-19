#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 这个就是用 定义了一个常量。 名字
// 在预处理阶段结束之后，会替换掉。 
// 名字要注意一下。 全大写，下划线分割。 
#define MAX_FILE_SIZE 4096


// 宏定义函数： 定义一个类似函数的东西。 
//#define SQRT(x) x*x
#define SQRT(x) (x)*(x)
//#define SQRT_DIFF(x,y) (x)*(x) - (y)*(y)
#define SQRT_DIFF(x,y) ((x)*(x) - (y)*(y))
// 宏定义函数，就是做文本替换。 一定要注意。 写宏定义函数的时候的写法。 
// 框框写  ()


int main(void) {

	// 预处理步骤，由预处理器执行。 主要负责处理
	// 预处理指令
	// #include ： 包含。 笼统的认为，就是复制粘贴。 
	// #define 

	int num = 66;
	printf("num = %d\n", num);
	printf("max_size = %d\n", MAX_FILE_SIZE);
	printf("sqrtttt = %d\n", SQRT(4));
	printf("sqrtttt = %d\n", SQRT(1 + 2));  // 1+2*1+2
	printf("sqrtttt = %d\n", SQRT_DIFF(5, 3) * 6);  // 1+2*1+2
	return 0;
}