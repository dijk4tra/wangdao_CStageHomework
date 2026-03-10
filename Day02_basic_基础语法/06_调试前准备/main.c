#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <test1.h>

int main(void) {
	// 调试，就是让程序跑起来，然后观察数据的变化。 
	// 如果程序压根运行不起来，这时候就无法进行调试。 
	// 所以，在调试之前，需要将编译错误，链接错误解决掉。 
	//a = 100;

	//print1("hello world\n");

	// 出现链接错误，就观察一下，函数名是否写对。是否正确包含了头文件。
	int a = 10;

	//错误示例，要注意区分 == 和 = 
	if (a = 20) {	
		printf("hello 20\n");
	}
	
    return 0;
}