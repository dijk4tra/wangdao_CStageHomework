#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr))/(sizeof(arr[0])))

void test1() {
    // 统计数组中的小写字母有多少个

    char str1[10] = { 'a','B','c','0','9','+','*','b','e','m' };

    int lower_count = 0;
    for (int i = 0; i < ARR_LEN(str1); i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            lower_count++;
        }
    }
    printf("数组中小写字母的个数为：%d\n", lower_count);
}

void test2() {
    // 如果是小写字母，转大写，如果是大写字母，转小写

    char str1[10] = { 'a','B','c','0','9','+','*','b','e','m' };

    for (int i = 0; i < ARR_LEN(str1); i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            // 'a' - 'A'
            // str1[i] = str1[i] - 32;
            str1[i] = str1[i] - ('a' - 'A');
        }
        else if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + ('a' - 'A');
        }
    }

    for (int i = 0; i < ARR_LEN(str1); i++){
        printf("======%c\n",str1[i]);
    }
    
    // 关于一种数据结构，遍历是一个核心操作
    // 因为大多数情况下，都需要通过遍历来完成业务逻辑
}


int main(void) {
    //test1();
    test2();
    return 0;
}