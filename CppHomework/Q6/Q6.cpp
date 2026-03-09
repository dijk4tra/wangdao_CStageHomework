#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int Funct(int n) {
	if (n == 0 || n == 1) return 1;

	int a = 1; // 代表第n-2项
	int b = 1; // 代表第n-1项
	int c;     // 代表第n项

	//从第2项开始计算，直到第n项
	for (int i = 1; i <= n; i++) {
		c = a + b; // 当前项等于前两项之和
		a = b;     // 往前移动一项
		b = c;     // 往前移动一项
	}
	return c; // 返回第n项的值
}


int main() {
	int n;
	printf("请输入斐波那契数列项数 n：");
	scanf("%d", &n);
	printf("Funct(%d) = %d\n", n, Funct(n));
	return 0;
}


/*
#include <stdio.h>

int Funct(int n){
	if (n==0 || n==1) return 1;
	int a=1; //代表第n-2项
	int b=1; //代表第n-1项
	int c; //代表第n项
	//从第2项开始计算，直到第n项
	for(int i=1;i<=n;i++){
		c=a+b; //当前项等于前两项之和
		a=b; //往前移动一项
		b=c; //往前移动一项
	}
	return c; //返回第n项的值
}

int main(){
	printf("请输入斐波那契数列项数 n：");
	int n;
	scanf("%d",&n);
	printf("Funct(%d)=%d",n,Funct(n));
	return 0;
}
*/