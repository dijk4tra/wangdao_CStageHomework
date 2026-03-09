#include <stdio.h>

int main() {
	printf("满足条件的数有: ");
	for (int i = 100; i <= 200; i++) {
		//判断是否同时满足3个取余条件
		if (i%3 == 2 && i%5 == 3 && i%7 == 2) {
			printf("%d ", i);
		}
	}
	return 0;
}

/*
#include <stdio.h>

int main(){
	printf("满足条件的数有：");
	for (int i=100;i<=200;i++){
		if (i%3==2 && i%5==3 && i%7==2) printf("%d",i);
	}
	return 0;
}
*/