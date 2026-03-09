#include <stdio.h>

int main() {
	printf("100~999之间的水仙花数有：\n");
	for (int n = 100; n <= 999; n++) {
		int i = n / 100;          // 百位数字
		int j = (n / 10) % 10;    // 十位数字
		int k = n % 10;           // 个位数字
		//检查是否为水仙花数
		if (n == (i * i * i + j * j * j + k * k * k)) {
			printf("%d\n", n);
		}
	}
	printf("\n");
	return 0;
}


/*
#include <stdio.h>
int main(){
	printf("100~999之间的水仙花数有：\n");
	for (int n=100;n<=999;n++){
		int i = n/100; //百位数字
		int j = (n/10）%10； //十位数字
		int k = n%10; //个位数字
		//检查是否为水仙花数
		if (n == i*i*i+j*j*j+k*k*k) printf("%d",n);
	}
	printf("\n");
	return 0;
}
*/