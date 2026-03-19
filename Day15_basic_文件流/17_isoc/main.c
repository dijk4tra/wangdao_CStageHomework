#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// ISO-C : ISO 是一个国际标准组织。 
	// 国际标准组织制定的一套C语言函数。 

	// void *malloc(size_t );
	// 我们在Linux之前学的所有函数，都是ISO-C。 
	// ISO-C ，约束力比较强。 在windows中能用，在Linux中能用，在Mac中也能用。 

	// 后期，进入Linux之后。 
	// POSIX-C ： POSIX标准委员会制定的一套C函数。 
	// 约束力比较差。 只能约束类Unix。Linux, Mac

}

void test2() {
	// ISO-C： 标准C。 
	// 一种C，是怎样产生的。 
	// 基本产出，只产出了标准。 具体的实现，一般不由这些人实现。 
	// 
	// POSIX-C ： 在Linux下有效的C。 
	// 为什么不全部都用ISO-C? 因为有的功能ISO-C没有。 

}


int main(void) {

	return 0;
}