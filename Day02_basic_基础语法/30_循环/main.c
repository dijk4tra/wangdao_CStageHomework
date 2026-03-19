#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// for循环 vs while循环（重点）
	// for和while循环是完全等价的，能用for一定能用while，能用while一定也能用for

	// 循环10次。 并且将值输出。 

	printf("for===============\n");
	for (int i = 0; i < 10; i++) {
		//i==> 0-9
		printf("for-----%d\n", i);
	}

	int count = 0;
	while (count < 10) {
		printf("while+++++++++++%d\n", count);
		count++;
	}

	// for循环，推荐用在确定次数的时候。 
	// while循环，用在循环次数未知，但是知道循环的中止条件。 

	// getchar() != '\n'
}

void test2() {

	int ch;
	while ((ch = getchar()) != '\n') {
		printf("while===========%c\n", ch);
	}

	for (int ch; ;) {
		ch = getchar();

		if (ch != '\n') {
			break;
		}

		printf("for-----------------%c\n", ch);
	}

}

void test3() {
	// continue
	// break
	// return
	// 后期会直接用，所以要注意一下。 
}

void test4() {
	// 注意常见运算符的优先级和结合性
	10 + 3 * 5 / 2;		// *、/的优先级高于+

	//10 + 5 >> 1 + 3 / 2 + a++;  //该表达式等价于(10 + 5) >> (1 + (3 / 2) + a)
}


int main(void) {

	test1();

	return 0;
}