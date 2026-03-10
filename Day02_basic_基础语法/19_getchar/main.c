#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // getchar
    char ch = 'z';
    putchar(ch);
}

void test2() {
    // getchar()就是从标准输出缓冲区 stdin 中一个字符一个字符获取
    int ch = getchar();
    printf("%d------%c\n", ch, ch);
}

void test3() {
    // getchar 有什么用？
    // 可以从标准输入中，一直获取数据
    int ch;
    while ((ch = getchar()) != '\n') {
        printf("--------%c\n", ch);
    }
}

void test4() {
	int ch;
	int low_alpha_count = 0;
	int high_alpha_count = 0;
	int digit_count = 0;

	while ((ch = getchar()) != '\n') {
		if (ch >= 'a' && ch <= 'z') {
			// 是一个小写字符。 
			//printf("%c是一个小写字符.\n", ch);
			low_alpha_count++;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			//printf("%c是一个大写字符.\n", ch);
			high_alpha_count++;
		}
		else if (ch >= '0' && ch <= '9') {
			//printf("%c是一个数字.\n", ch);
			digit_count++;
		}

		//printf("--------%c\n", ch);
	}
}

void test5() {
    // getchar 可以用于清楚缓冲区的脏数据
    
    int ch;
    while ((ch = getchar()) != '\n');

	// scanf("%d %d", &num1, &num2);
	// 10 30 
	// 10aaaaa33
}

void test6() {
	// 思考：图片是怎么存的，是视频怎么存的？
}

int main(void) {
	//test1();
	//test2();
	//test3();
	test4();
	//test5();
    return 0;
}