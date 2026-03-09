#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	int n;
	printf("请输入一个自然数：");
	scanf("%d", &n);

	printf("%d=1", n); //按照要求，先输出“n=1”
	
	int i = 2;
	//当n仍大于1时，继续分解
	while (n > 1) {
		if (n % i == 0) {
			printf("*%d", i); //输出当前的因子
			n = n / i;        //更新n的值
		}
		else {
			i++;              //除不尽，尝试下一个可能的因子
		}
	}
	printf("\n");
	return 0;
}


/*
#include <stdio.h>

int main(){
	int n;
	printf("请输入一个自然数：");
	scanf("%d",&n);

	printf("%d=1",n);//先输出“n=1”

	int i=2;
	//当n仍大于1时，继续分解
	while(n>1){
		if(n%i == 0) {
			printf("*%d",i); //输出当前因子
			n = n/i; //更新n的值
		}
		else{
			i++; //除不尽，尝试下一个可能的因子
		}
	}
	printf("\n");
	return 0;
}

*/