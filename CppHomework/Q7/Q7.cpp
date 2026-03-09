#include <stdio.h>

int main() {
	int arr[] = {8, 6, 5, 4, 1 };
	int len = 5;
	printf("原数组：");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	//核心逻辑：首尾交换
	for (int i=0; i<len/2; i++){
		int temp = arr[i];	//保存前半部分元素
		arr[i] = arr[len - 1 - i];	//交换前后元素
		arr[len - 1 - i] = temp; //将保存的前半部分元素赋值给后半部分
	}
	printf("\n逆序后的数组：");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}



/*
#include <stdio.h>
int main(){
	int arr[]={8,6,5,4,1};
	int len=5;
	printf("原数组：");
	for(int i=0; i<len/2; i++){
		printf("%d",arr[i]);
	}
	//核心逻辑：首尾交换
	for(int i=0; i<len/2 ; i++){
		int temp = arr[i]; //保存前半部分元素
		arr[i] = arr[len-1-i]; //交换前后元素
		arr[len-1-i] = temp; //将保存的前半部分元素赋值给后半部分
	}

	printf("\n逆序后的数组：");
	for(int i=0; i<len/2; i++){
		printf("%d",arr[i]);
	}
	return 0;
}
*/