#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 字符串字面值：是使用字符数组存储，以 \0 结尾

    // 存储位置是在只读数据段上
    printf("s", "hello");

	// 大小是6，hello占5. \0 自动补一个。 
	printf("%d\n", sizeof("hello"));

	// p指针，指向只读数据段这块空间。 
	char *p = "nihao";

	*p = 'H'; // 只读数据段是无法修改的，一修改就报错。
	printf("%c", *p++);
	printf("%c", *p++);
	printf("%c", *p++);
	printf("%c", *p++);
}

void test2() {
	// 以下场景中，"hello"在代码中会被视为数组名，也即首元素指针

	// 指针p指向数据段中的只读字符串字面值数组，此时指针p无法修改指向内容
	char *p = "hello";

	// &"hello"是允许的，类型是 char (*)[6]，即指向6个字符数组的指针类型。但这种语法不常见，了解即可
	char *p2 = &"hello";    // 隐式类型转换

	// 既然被视为数组名，就支持索引运算。字符c此时是'o'
	char c1 = "hello"[4];

	// 指针p_element指向字符'o'
	char *p_element = "hello" + 4;

	// 索引运算就是算术运算和解引用运算的语法糖。字符c此时是'o'
	char c2 = *("hello" + 4);
}


int main(void) {

	test1();

	return 0;
}