#include <stdio.h>

int main() {
	//i代表行, j代表列
	//当列号j>=行号i时，打印1，否则打印(i-j+1)
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j >= i) printf("1");
			else printf("%d", i - j + 1);
		}
		printf("\n"); //每行结束时换行
	}
	return 0;
}