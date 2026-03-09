#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，计算从1加到n的和，其中n由用户输入。

要求：
1. 使用scanf()接收用户输入的正整数n
2. 使用for循环计算1到n的和
3. 输出格式为："1到%d的和是: %d"

考点： for循环
*/

int main(void) {
    int n = 0;
    int sum = 0;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    printf("1到%d的和是: %d\n", n, sum);
    return 0;
}

/*
int main(void) {
    int n = 0;
    int sum = 0;
    printf("请输入一个正整数：\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("1到%d的和是: %d", n, sum);
    return 0;
}
*/