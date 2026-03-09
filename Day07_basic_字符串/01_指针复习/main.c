#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 虚拟内存：虚拟的内存。与之相对的是物理内存。 
	// 程序运行过程中看到的内存都是虚拟的内存地址。
	// 虚拟内存的优点：
	// 1.进程间隔离更容易。
	// 2.内存碎片问题。
	// 3.解决了程序员手动管理内存的麻烦。
	// 
	// 内存地址 
	// 变量地址：变量如果有多个字节，得到变量的地址的时候都是首字节地址。 

	char ch = '1';
	char *p_ch = &ch;

	int num1 = 1008611;

	double d1 = 3.1515;

	int *p_num1 = &num1;
	double *p_d1 = &d1;
}

void test2() {
	// 小端存储法是什么意思？
	// 数据的低位存储在低地址

	// 1008611
	// 数据的高位              数据的低位。 
	// 00      0F      63      E3

	//    1            2              3              4           5....
	//   E3           63              0F            00
	// 明白小端存储法，才能知道，看内存怎么看。 
}

void test3() {
	int num1 = 10;
	int num2 = 20;

	int *p1 = &num1;
	*p1 = 999;

	int *p2 = *p1;
	int *p3 = p1;
	int *p4 = &p1;
}

void test4() {
	// 指针和数组。 
	// 指针的算术运算。 
	char arr[] = { 'a', 'b', 'c', 'c', 'd', 'e', '1', '2' };

	// 数组名，大多数情况，当做数组首元素指针对待。 
	// 以下两种情况除外：
	// &arr;
	// sizeof(arr)


	// 使用数组名，给一个指针赋值。 

	char *p1 = arr;
	p1[0] = 'z';

	// 指针，只是地址。 你需要关注的是，这个指针到底指向了哪里。 
	// 关键不在指针，在指针到底指向了哪块内存。 

}

void test5() {
	// 指针的算术运算。 
	// 指针是可以进行加减的。加减的单位，是指针指向数据类型的大小。 
	// 如果是int指针，+3，相当于就是偏移3*4个字节。 
	// 如果是double指针。+5，相当于就是偏移 5*8 个字节。 
	char arr1[] = { 'a', 'b', 'c', 'c', 'd', 'e', '1', '2' };
	char *p_arr1 = arr1;
	printf("%c\n", *(p_arr1 + 0));
	printf("%c\n", p_arr1[0]); // [] 相当于解了一次引用。 
	//printf("%c\n", p_arr1 + 0);

	printf("%c\n", *(p_arr1 + 1));
	printf("%c\n", p_arr1[1]); // 

	printf("%c\n", *(p_arr1 + 2));
	printf("%c\n", p_arr1[2]);
	printf("%c\n", p_arr1[7]);  // 

	int arr2[] = { 10,20,30,40,50,60,70 };

	//int *p_arr2 = *arr2;
	//int *p_arr2 = &arr2;
	int *p_arr2 = arr2;
	printf("%d\n", p_arr2[0]);
	printf("%d\n", p_arr2[5]); // 5 * 4(单个类型占据空间大小)

	double arr3[] = { 3.14,4.55,6.78,9.22,10.66 };
	double *p_arr3 = arr3;

	printf("%lf\n", *(p_arr3 + 3));
}

int main(void) {
	
	//test1();
	test5();

	return 0;
}