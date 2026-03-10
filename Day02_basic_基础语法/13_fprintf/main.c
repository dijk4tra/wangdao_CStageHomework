#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // printf：输出，往屏幕输出
    // scanf：输入，从键盘输入
    
    // 同族函数。输入和输出，只是目的地不同
    
    // fprintf：输出，文件输出
    // sprintf：输出，字符串输出

    printf("num1=%d num2=%d\n", 10, 99999);
    //fprintf(fp, "num1=%d num2=%d\n", 10, 99999);
    //sprintf(buf, "num1=%d num2=%d\n", 10, 99999);

    // fscanf: 输入，从文件输入
    // sscanf: 输入，从字符串输入
}

int main(void) {
    
    return 0;
}