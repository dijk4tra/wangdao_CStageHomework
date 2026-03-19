#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 二级指针，就是指针的指针，也就是存储指针地址的变量
	int num = 10;
	int num2 = 9990;

	int *p1 = &num;  // 一级指针p1指向变量num
	// *p1 = 10086;  // 可以通过*p1修改num的值

	// 如果想改变p1的指向，让其指向num2
	//p1 = &num2;    // 直接修改p1的指向

	// 通过二级指针修改一级指针的指向
	int **pp1 = &p1; // 二级指针pp1存储了一级指针p1的地址
	*pp1 = &num2;	 // 对二级指针解引用得到p1，然后修改p1的指向为num2

	// 此时p1已经指向了num2，所以*p1输出的是num2的值
	printf("%d\n", *p1); // 输出 9990
}

// 尝试通过传值方式修改外部int变量——无法实现
void change_int_by_int(int num) {
	// 函数内部，去修改外部调用者的int值
	// 参数num是实参的副本，修改此副本不会影响实参
	num = 10086;  // 只修改了局部副本
}

// 通过指针参数修改指针所指向的变量值——可以实现
void change_int_by_pointer(int *p1) {
	// p1是指针，实参传递的是地址，通过*p1可以修改该地址处的变量
	*p1 = 9998887;  // 修改了p1所指向的变量
}

int global_num = 654654654;
// 尝试通过指针参数修改指针本身的指向——无法实现
void change_pointer_by_pointer(int *p1) {
	// p1本身是指针变量，但作为参数传递时，也是值传递（传递的是指针的值，即地址）
	// 修改p1本身（让其指向别处）只是修改了函数内部的局部指针变量，不影响外部实参
	p1 = &global_num;
	printf("in change_pointer_by_pointer num = %d\n", *p1);
}

// 通过二级指针参数修改一级指针的指向——可以实现
void change_pointer_by_pointerpointer(int **pp) {
	// pp是二级指针，指向一级指针变量
	// *pp解引用得到一级指针，对其赋值即可修改一级指针的指向
	*pp = &global_num;
}

void test3() {
	//int a = 10;
	//change_int_by_int(a);					// 值传递，a不会被修改
	//printf("change after=====%d\n", a);   // 仍输出10

	//int a = 10;
	//int *p1 = &a;
	//change_int_by_pointer(p1);			// 通过指针修改a的值
	//printf("change after=====%d\n", a);   // 输出9998887

	int a = 10;
	int *p1 = &a;
	//change_pointer_by_pointer(p1);					// 试图修改p1的指向，失败
	//printf("change after pointer=====%d\n", *p1);		// 仍输出10

	int **pp1 = &p1;	// 定义二级指针pp1指向p1
	change_pointer_by_pointerpointer(pp1);	// 通过二级指针修改p1的指向
	printf("change after pointerpointer=====%d\n", *p1); // 输出global_num的值
}


void test2() {
	// 二级指针，是存储一级指针的地址的指针。 
	// 它有什么用? 
	// 1. 在函数中修改一级指针的指向（如test3所示）
	// 2. 动态分配二维数组或指针数组时使用
	// 3. 实现链表、树等数据结构时，可能需要二级指针来修改头指针
	// 4. 多级指针的扩展
}


int main(void) {

	//test1();
	test3();

	return 0;
}