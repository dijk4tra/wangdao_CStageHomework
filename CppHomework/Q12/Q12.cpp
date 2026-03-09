#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	//定义一个足够大的数组，假设已有5个有序元素
	int a[10] = {1, 33, 45, 78, 97};
	int n = 5; // 当前数组中已有元素的个数
	int x, i, j;

	printf("原数组:");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n请输入要插入的数：");
	scanf("%d", &x);
	//从后向前找到插入位置
	for (j = n - 1; j >= 0; j--) {
		if (a[j]>x) {
			a[j + 1] = a[j]; //元素后移
		}
		else {
			break; //找到插入位置，跳出循环
		}
	}
	//把x插入到空出来的位置(a[j]的后面)
	a[j + 1] = x; //插入元素
	n++; //数组元素个数加1

	printf("插入后的数组:");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}

/*
#include <stdio.h>

int main(){
	//定义一个足够大的数组，假设其中已经有5个元素
	int a[10] = {1,5,24,67,90};
	int n = 5; //当前数组中已有元素的个数
	int x,i,j;

	printf("原数组：")；
	for (i = 0; i < n ;i++){
		printf("%d ",a[i]);	
	}

	printf("请输入要插入的整数：")；
	scanf("%d",x);

	//从后向前找到插入位置
	for(j = n-1 ;j >= 0; j--){
		if(a[j] > x){
			a[j+1] = a[j];
		}
		else{
			break; //找到插入位置，跳出循环
		}
	}
	//把x插入到空出来的位置（a[j]的后面）
	a[j+1] = x;
	n++; //数组元素个数加1

	printf("插入新数后的数组：")
	for (i = 0; i < n ; i++){
		printf("%d",a[i]);
	}

	return 0;
}
*/