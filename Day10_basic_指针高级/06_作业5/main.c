#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	char fruits1[][10] = {
		"apple",
		"banana",
		"cherry"
	};

	// //	请分别将两个字符串数组中的第一个字符串，修改成"orange"。
	//fruits1[0] = "orange"; 

	// 指针数组： 数组。 指针。
	char *fruits2[] = {
	"apple",
	"banana",
	"cherry"
	};
	//fruits2[0] = "orange";
	//strcpy(fruits2[0], "orange");


	//在main函数当中，先写出下列代码，用两种不同的方式来定义实现字符串数组：

	//	// char类型二维数组实现字符串数组
	//	char fruits1[][10] = {
	//	"apple",
	//	"banana",
	//	"cherry"
	//};

	//// char*指针数组实现字符串数组
	//char *fruits2[] = {
	//"apple",
	//"banana",
	//"cherry"
	//};
	//请完成以下编程或者回答相应的问题。

	//	题目一：
	//	请分别遍历 fruits1 和 fruits2这两个字符串数组，输出每个字符串的内容及其长度。
	// strlen 

	//	题目二：

	//	请分别将两个字符串数组中的第一个字符串，修改成"orange"。

	//	首先你需要回答：基于"="运算符直接赋值修改，能不能完成这样的操作？如果不能为什么？

	//	提示：通过一定的手段，两个都可以完成修改。参考代码仅提供一种实现方式，若你能够实现，亦可采用自己的实现。

	//	题目三：

	//	请分别将两个字符串数组中的第二个字符串"banana"中的第一个字符'b'，修改成'B'。

	//	首先你需要回答：基于"="运算符直接赋值修改，能不能完成这样的操作？如果不能为什么？

	//	提示：通过一定的手段，两个都可以完成修改。参考代码仅提供一种实现方式，若你能够实现，亦可采用自己的实现。

	//	题目四：
	// 请自行定义初始化一个字符串数组fruits3，
	// 使得这个字符串数组既可以通过"="直接修改整个字符串的内容，
	// 也可以利用"="修改某个字符串的某个字符。

	//	提示：实现方式不唯一，参考代码仅提供一种实现参考。
}

void test2() {
	// 关于指针的问题。 

	// 如果一个指针，是 int *
	// int *可以指向谁，有什么含义。 
	// int *可以指int 数组。 int 
	int arr[] = { 10,20,30,40,50 };
	int *p = arr;

	// *p ==> 找出来了一个int类型的数据。 
	// 找回来了 10这个数据。 

	int val = *p + 100;
	// *p + 100;

	// int *可以指int数组。 int *
	// 算术运算。  一次偏移多个字节，也是 int *整的活。 
	// int * +1  偏移  int字节
	// int ** +1 偏移  int *字节。 
}

void test3() {
	// 字符串的两种存储方式。 
	// 二维数组。 指针数组。 

	// 如果我想使用指针来接二维数组。应该用什么指针？
	// 数组指针。 

	// 	int * +1  偏移  int字节
	// int ** +1 偏移  int *字节。 

	// 指针数组来存储字符串数组。 
	// 二级指针。 

	char fruits1[][10] = {
		"apple",
		"banana",
		"cherry"
	};

	char *fruits2[] = {
	"apple",
	"banana",
	"cherry"
	};
	char(*p1)[10] = fruits1;
	printf("%s\n", *p1);
	printf("%s\n", *(p1 + 1));

	char **pp2 = fruits2;
	printf("%s\n", *pp2);
	printf("%s\n", *(pp2 + 1));
}



int main(void) {

	test3();

	return 0;
}