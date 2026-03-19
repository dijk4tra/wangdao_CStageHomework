#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
读下列一段程序代码，回答以下一些问题。

#include <stdio.h>

static int global = 1;  // 全局变量

void modify(int param) {
	static int static_local = 1;  // 静态局部变量
	int local = 1;                // 普通局部变量

	// 修改函数传参的值
	param *= 2;
	// 修改全局变量
	global *= 2;
	static_local *= 2;    // 修改静态局部变量
	local *= 2;    // 修改普通局部变量

	printf("test函数内部：param=%d, global=%d, static_local=%d, local=%d\n",
		param, global, static_local, local);
}

void modify_global(int global) {
	global = 100;
}

int main(void) {
	int param_a = 10;
	int param_b = 20;
	printf("初始值：param_a=%d, param_b=%d, global=%d\n\n", param_a, param_b, global);

	modify(param_a);
	printf("第一次调用后：param_a=%d, global=%d\n\n", param_a, global);

	modify(param_b);
	printf("第二次调用后：param_b=%d, global=%d\n\n", param_b, global);

	modify_global(global);
	printf("after modify_global global = %d\n", global);

	return 0;
}
问题一：
通过modify函数调用，能不能修改"param_a"和"param_b"的取值呢？为什么？

问题二：
能不能在main函数当中访问静态局部变量"static_local"呢？为什么？

问题三：
全局变量"global"使用static修饰，这里的static关键字是什么作用？

问题四：
modify函数的两次调用中，"printf"输出打印的自身局部变量"local"的取值是一样的吗？为什么？

问题五：
modify函数内部修改了全局变量"global"的取值，两次调用"printf"函数输出的结果是什么？为什么？

问题六：
modify函数内部修改了静态局部变量"static_local"的取值，两次调用"printf"函数输出的结果是什么？为什么？

问题七：
modify_global函数希望修改"global"全局变量的取值，可以修改成功吗？为什么？

*/

/*

1.不能通过modify函数调用修改"param_a"和"param_b"的取值。因为C语言的函数参数传递机制是"值传递（call by value）"的。这意味着当我们调用一个函数并将实参进行传递时，实际上是将实参的值复制给函数的形参，或者说是将实参的一个副本传递给了函数。因此，函数内对形参的任何更改都不会影响到实参，因为函数内部修改的只是实参的副本，而不是实参本身。
2.不能在main函数当中访问静态局部变量"static_local"。因为静态局部变量的作用域仅限于所在函数。static_local 是在modify函数内部定义的局部变量，它的作用域被严格限制在 modify 函数的 {} 内部。
3.这里的static关键字的作用是将该全局变量的作用域限制在声明它的文件中，该全局变量只能在它所在的源文件中被访问和修改。
4.是一样的，两次的值都为2。因为局部变量在每次函数调用时都初始化。而local就是一个局部变量，存储在栈区。每次调用modify函数时，系统都会为它重新分配内存，并执行初始化int local = 1;，随后执行乘以2的操作，函数退出后local就会被销毁。
5.第一次输出global=2，第二次输出global=4。全局变量global存储在数据段，其生命周期一直从程序启动到程序结束，其只在函数最开头被初始化一次，且不会因为函数的退出而销毁。第一次调用modify时，它由初始的1变成了2；第二次调用modify时，它是在上一次运算结果2的基础上继续乘以2，因此变成了4。
6.第一次输出 static_local=2，第二次输出 static_local=4。 使用 static 修饰的局部变量同样存储在静态数据区。它的初始化语句 static int static_local = 1; 仅仅在代码第一次执行到这里时运行一次。当函数执行结束时，该变量不会被销毁，而是保留了最后的值。因此，它的数值变化表现得和全局变量一样，具有记忆功能。
7.修改不成功。这里发生了“变量遮蔽（Variable Shadowing）”。因为在modify_global函数中，形参的名字也叫global。当局部变量（形参）和全局变量同名时，在函数内部局部变量的优先级更高。因此，语句global = 100; 实际上修改的只是作为局部变量的形参副本，真正的全局变量global并没有被修改。

*/





int main(void) {
    printf("hello world!\n");
    return 0;
}