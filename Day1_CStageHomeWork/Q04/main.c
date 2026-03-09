#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
经典循环案例：请求出所有的水仙花数，并统计总共有几个。
所谓的水仙花数是指一个三位数，其各位数字的立方和等于该数本身。
举例：153就是一个水仙花数，153 = 1 * 1 * 1 + 5 * 5 * 5 + 3 * 3 * 3 = 1 + 125 + 27 = 153
*/
int main(void) {
    printf("以下是所有的水仙花数：\n");
    for (int n = 1; n <= 999; n++) {
        int i = n / 100;        //百位数字
        int j = (n / 10) % 10;  //十位数字
        int k = n % 10;         //个位数字

        if (n == i * i * i + j * j * j + k * k * k) {
            printf("%d\n", n);
        }
    }
    return 0;
}