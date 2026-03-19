#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h> //若没有 #include <stdint.h>，编译器看到 int32_t 就会报错，因为它不知道这是一个类型

typedef int DataType;

void test1() {
	// 类型别名，就是可以为系统中的一些原有类型，取别的名字

	DataType data = 10;
	printf("%d\n", data);

	// Node 
}

void test2() {
	// 如果在系统中，大量使用的某一个变量，是int
	// 大多数情况下，是4个字节。 

	// 过了一段时间，我们发现4个字节不够装，需要改为8个字节的long long
	// 要是一个一个更改代码中的int为long long，那就太麻烦了
	// 但要是我们使用的是DataType这个别名（typedef int DataType;）
	// 那我们就只需要改动typedef int DataType; ，将其改为 typedef long long DataType即可

	// 可以提升代码的跨平台移植性
	// 大多数情况下，int是4个字节，但可能在一些低配置设备的系统，其int是2个字节
	// 对于这种情况，使用typedef int DataType;也可以很大程度上便利代码的跨平台移植

}


void test3() {
	// 在Linux系统中，大量使用了类型别名。 

	// sizeof()
	// 系统提供的类型别名，基本有一个特征。 以  _t 
	// 见到 _t 一定要知道它是类型别名。 

	// size_t: 是一个和系统位数相关的无符号整数
	// size_t是C/C++标准库中定义的一个无符号整数类型，专门用来表示内存中对象的大小（以字节为单位）或数组的索引
	printf("%zu\n", sizeof(size_t)); // 因为是在x86（32位）环境下运行的，其输出为4（4Byte，也就是32位）

	int8_t;
	printf("%d\n", sizeof(int8_t));
	int16_t;
	printf("%d\n", sizeof(int16_t));
	int32_t;
	printf("%d\n", sizeof(int32_t));
	uint32_t;
	printf("%d\n", sizeof(uint32_t));

	// 存在的意义：消除平台差异，确保确定性
	// 例如int8_t：无论是在8位微控制器、32位ARM芯片，还是64位服务器上，它必须被定义为刚好8bit(1字节)
}

int main(void) {

	test3();

	return 0;
}