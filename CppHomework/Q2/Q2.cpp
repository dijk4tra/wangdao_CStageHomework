#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	char lower;
	printf("请输入一个小写字母：");
	scanf("%c", &lower);	//读取用户输入的字符赋给变量lower

	if (lower >= 'a' && lower <= 'z') {		//判断输入是否为小写字母
		char upper = lower - 32; //转换为大写字母
		printf("该小写字母对应的大写字母是：%c\n", upper); //输出结果
	}
	else {
		printf("当前输入不是小写字母！\n");
	}

	return 0;
}


/*
#include <stdio.h>

int main(){
	char lower;
	printf ("请输入一个小写字母：")；
	scanf （"%c",&lower）;

	if (lower>='a' && lower <= 'z') {
		char upper = lower - 32;
		printf("该小写字母对应的大小字母为：%c\n",upper);
	}
	else{
		printf("当前输入的字母不是小写字母！")；
	}

	return 0；
}
*/